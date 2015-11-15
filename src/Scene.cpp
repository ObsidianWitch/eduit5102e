#include <glm/glm.hpp>

#include "Scene.hpp"
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
    skybox()
{
    // key & mouse handlers
    Inputs::instance().addKeyHandler(player.getEventHandler());
    Inputs::instance().addMouseHandler(player.getEventHandler());
    Inputs::instance().addMouseHandler(camera.getEventHandler());
    Inputs::instance().addWindowHandler(camera.getEventHandler());
    
    // shaders
    mainShader.add(GL_VERTEX_SHADER, "src/shaders/main/main.vs")
              .add(GL_FRAGMENT_SHADER, "src/shaders/main/main.fs")
              .add(GL_FRAGMENT_SHADER, "src/shaders/main/toon.fs")
              .add(GL_FRAGMENT_SHADER, "src/shaders/main/lights.fs")
              .link();
    
    skyboxShader.add(GL_VERTEX_SHADER, "src/shaders/skybox/skybox.vs")
                .add(GL_FRAGMENT_SHADER, "src/shaders/skybox/skybox.fs")
                .link();
    
    // lights
    addLight(new AmbientLight(
        "aL",                       // name
        glm::vec3(0.1f, 0.1f, 0.1f) // color
    ));
    
    addLight(new DirectionalLight(
        "dL",                        // name
        glm::vec3(1.0f, -0.5f, 0.0f), // direction
        glm::vec3(0.8f, 0.8f, 0.8f)   // color
    ));
    
    // background objects
    /// ground
    bgObjects.push_back(BgObject(
        "resources/ground/ground.obj",     // file path
        glm::vec3(0.0f),                   // position
        glm::vec3(1000.0f, 1.0f, 1000.0f), // scaling vector
        false                              // silhouette
    ));
    
    ///tree
    bgObjects.push_back(BgObject(
        "resources/tree1/Forest_tree.obj",
        glm::vec3(20.0f, 0.0f, 0.0f),                     // position
        glm::vec3(10.0f),                                 // scaling vector
        BoundingBox(glm::vec3(-10.0f), glm::vec3(10.0f)), // bounding box
        false                                             // silhouette
    ));
}

void Scene::update() {
    mainShader.use();
    
    player.move();
    for (auto o : bgObjects) {
        if (player.collide(o)) {
            player.cancelMove();
            break;
        }
    }
    player.update(mainShader);
    camera.update(mainShader, player.getPosition());
    updateEntities(mainShader);
    
    
    skyboxShader.use();
    camera.update(skyboxShader, false);
    skybox.update(skyboxShader);
}

void Scene::addLight(Entity* light) {
    lights.push_back(std::shared_ptr<Entity>(light));
}

void Scene::addBgObject(BgObject& bgObject) {
    bgObjects.push_back(bgObject);
}

void Scene::updateEntities(Shader& shader) {
    for (auto e : lights) {
        e->update(shader);
    }
    
    for (auto o : bgObjects) {
        o.update(shader);
    }
}
