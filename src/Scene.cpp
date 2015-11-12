#include <glm/glm.hpp>

#include "Scene.hpp"
#include "inputs/Inputs.hpp"
#include "entities/lights/AmbientLight.hpp"
#include "entities/lights/DirectionalLight.hpp"

Scene::Scene(GLuint width, GLuint height) :
    player(
        glm::vec3(0.0f, 0.0f, 0.0f), // position
        0.3f                         // speed
    ),
    camera(
        glm::vec3(0.0f, 10.0f, -10.0f), // position
        player.getPosition(),           // target
        glm::vec3(0.0f, 10.0f, 0.0f),   // target offset
        glm::radians(90.0f),            // fov
        width, height,                  // width & height
        0.1f, 100.0f                    // zNear & zFar
    ),
    skybox()
{
    // key & mouse handlers
    Inputs::instance().addKeyHandler(player.getInputHandler());
    Inputs::instance().addMouseHandler(player.getInputHandler());
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
    AmbientLight aL(
        "aL",                       // name
        glm::vec3(0.1f, 0.1f, 0.1f) // color
    );
    lights.push_back(&aL);
    
    DirectionalLight dL(
        "dL",                          // name
        glm::vec3(-1.0f, -0.5f, 0.0f), // direction
        glm::vec3(1.0f, 1.0f, 1.0f)    // color
    );
    lights.push_back(&dL);
    
    mainShader.use();
    aL.update(mainShader);
    dL.update(mainShader);
}

void Scene::update() {
    mainShader.use();
    player.update(mainShader);
    camera.update(mainShader, player.getPosition());
    
    skyboxShader.use();
    camera.update(skyboxShader, false);
    skybox.update(skyboxShader);
}
