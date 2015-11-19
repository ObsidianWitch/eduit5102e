#include <glm/glm.hpp>

#include "scenes/Scene.hpp"
#include "scenes/Forest.hpp"
#include "inputs/Inputs.hpp"
#include "entities/lights/AmbientLight.hpp"
#include "entities/lights/DirectionalLight.hpp"

Scene::Scene(GLuint width, GLuint height) :
    player(
        glm::vec3(0.0f, 0.0f, 0.0f), // position
        0.2f                         // speed
    ),
    camera(
        glm::vec3(0.0f, 10.0f, -10.0f), // position
        player.getPosition(),           // target
        glm::vec3(0.0f, 10.0f, 0.0f),   // target offset
        glm::radians(90.0f),            // fov
        width, height,                  // width & height
        0.1f, 1000.0f                   // zNear & zFar
    ),
    skybox(),
    forest(300.0f, 50) // radius, nTrees
{
    // key & mouse handlers
    Inputs::instance().addKeyHandler(player.getEventHandler());
    Inputs::instance().addMouseHandler(player.getEventHandler());
    Inputs::instance().addMouseHandler(camera.getEventHandler());
    Inputs::instance().addWindowHandler(camera.getEventHandler());
    
    // forest
    const auto& forestBgObjs = forest.getBgObjects();
    bgObjects.reserve(forestBgObjs.size());
    for (BgObject* o : forestBgObjs) { bgObjects.push_back(o); }
    
    // lights
    lights.push_back(std::make_shared<AmbientLight>(
        "aL",                       // name
        glm::vec3(0.1f, 0.0f, 0.0f) // color
    ));
    
    lights.push_back(std::make_shared<DirectionalLight>(
        "dL",                         // name
        glm::vec3(1.0f, -0.5f, 0.0f), // direction
        glm::vec3(0.9f, 0.7f, 0.7f)   // color
    ));
    
    lights.push_back(std::make_shared<PointLight>(
        "pL",                           // name
        glm::vec3(10.0f, 10.0f, 10.0f), // position
        glm::vec3(0.9f, 0.57f, 0.16f),  // color
        0.1f,                           // constant
        0.09f,                          // linear
        0.01f                           // quadratic
    ));
    
    // Collidables
    collidables.reserve(bgObjects.size());
    for (Collidable* c : bgObjects) { collidables.push_back(c); }
    
    // Renderers
    playerRenderer = std::make_unique<PlayerRenderer>(
        player, camera, lights
    );
    bgObjectsRenderer = std::make_unique<BgObjectsRenderer>(
        bgObjects, camera, lights
    );
    skyboxRenderer = std::make_unique<SkyboxRenderer>(
        skybox, camera
    );
    waterfallRenderer = std::make_unique<WaterfallRenderer>(
        forest.getWaterfall(), camera, lights
    );
}

void Scene::update() {
    // logic
    player.move();
    for (Collidable* c : collidables) {
        if (player.collide(*c)) {
            player.cancelMove();
            break;
        }
    }
    
    camera.setTarget(player.getPosition());
    
    forest.update();
    
    // render
    playerRenderer->render();
    bgObjectsRenderer->render();
    skyboxRenderer->render();
    waterfallRenderer->render();
}
