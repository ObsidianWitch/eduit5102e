#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "inputs/Inputs.hpp"
#include "shaders/Shader.hpp"
#include "entities/camera/Camera.hpp"
#include "entities/player/Player.hpp"
#include "entities/lights/AmbientLight.hpp"
#include "entities/lights/DirectionalLight.hpp"

const GLuint WIDTH = 800;
const GLuint HEIGHT = 600;

GLFWwindow* window = nullptr;

void errorCallback(int, const char* description) {
	std::cerr << description << std::endl;
}

/**
 * Initializes GLFW (window & callbacks), GLEW (extensions), and some OpenGL
 * features.
 */
void initLibraries() {
    // GLFW
    glfwSetErrorCallback(errorCallback);
    
    if (!glfwInit()) {
        std::cerr << "Failed to initialize GLFW" << std::endl;
        exit(EXIT_FAILURE);
    }
    
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    
    window = glfwCreateWindow(
        WIDTH, HEIGHT, "OpenGL Application", nullptr, nullptr
    );
    if (!window) {
        std::cerr << "Failed to open GLFW window" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    glfwMakeContextCurrent(window);
    glfwSwapInterval(1);
    
    glfwSetKeyCallback(window, Inputs::instance().keyCallback);
    glfwSetMouseButtonCallback(window, Inputs::instance().mouseButtonCallback);
    glfwSetCursorPosCallback(window, Inputs::instance().cursorPositionCallback);
    glfwSetScrollCallback(window, Inputs::instance().scrollCallback);
    
    // GLEW
    glewExperimental = GL_TRUE;
    if (glewInit() != GLEW_OK) {
        std::cerr << "Failed to initialize GLEW" << std::endl;
        glfwTerminate();
        exit(EXIT_FAILURE);
    }
    
    // OpenGL
    glViewport(0, 0, WIDTH, HEIGHT);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LESS);
}

/**
 * Deallocate resources and close the GLFW window.
 */
void terminate() {
    glfwDestroyWindow(window);
    glfwTerminate();
}

int main() {
    initLibraries();
    
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    
    Shader mainShader;
    mainShader.add(GL_VERTEX_SHADER, "src/shaders/main/main.vs")
              .add(GL_FRAGMENT_SHADER, "src/shaders/main/main.fs")
              .add(GL_FRAGMENT_SHADER, "src/shaders/main/toon.fs")
              .add(GL_FRAGMENT_SHADER, "src/shaders/main/lights.fs")
              .link();
    
    Player player(
        glm::vec3(0.0f, 0.0f, 0.0f), // position
        0.3f                         // speed
    );
    Inputs::instance().addKeyHandler(player.getInputHandler());
    Inputs::instance().addMouseHandler(player.getInputHandler());
    
    Camera camera(
        glm::vec3(0.0f, 10.0f, -10.0f), // position
        player.getPosition(),           // target
        glm::vec3(0.0f, 10.0f, 0.0f),   // target offset
        glm::radians(90.0f),            // fov
        WIDTH,                          // width
        HEIGHT,                         // height
        0.1f,                           // zNear
        100.0f                          // zFar
    );
    Inputs::instance().addMouseHandler(camera.getMouseHandler());
    
    AmbientLight aL(
        "aL",                       // name
        glm::vec3(0.1f, 0.1f, 0.1f) // color
    );
    
    DirectionalLight dL(
        "dL",                          // name
        glm::vec3(-1.0f, -0.5f, 0.0f), // direction
        glm::vec3(1.0f, 1.0f, 1.0f)    // color
    );
    
    mainShader.use();
    aL.update(mainShader);
    dL.update(mainShader);
    
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        mainShader.use();
        
        player.update(mainShader);
        camera.update(mainShader, player.getPosition());
        glfwSwapBuffers(window);
    }
    
    terminate();
    
    return EXIT_SUCCESS;
}
