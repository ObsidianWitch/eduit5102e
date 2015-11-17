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
    forest(100.0f) // radius
{
    // key & mouse handlers
    Inputs::instance().addKeyHandler(player.getEventHandler());
    Inputs::instance().addMouseHandler(player.getEventHandler());
    Inputs::instance().addMouseHandler(camera.getEventHandler());
    Inputs::instance().addWindowHandler(camera.getEventHandler());
    
    // lights
    lights.push_back(std::make_unique<AmbientLight>(
        "aL",                       // name
        glm::vec3(0.1f, 0.0f, 0.0f) // color
    ));
    
    lights.push_back(std::make_unique<DirectionalLight>(
        "dL",                        // name
        glm::vec3(1.0f, -0.5f, 0.0f), // direction
        glm::vec3(0.8f, 0.8f, 0.8f)   // color
    ));
    
    // background objects
    /// forest
    const auto& forestBgObjs = forest.getBgObjects();
    bgObjects.reserve(forestBgObjs.size());
    for (BgObject* o : forestBgObjs) { bgObjects.push_back(o); }
    
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
    
    // render
    playerRenderer->render();
    bgObjectsRenderer->render();
    skyboxRenderer->render();
}
