#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>

#include "inputs/Inputs.hpp"
#include "scenes/Scene.hpp"

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
    //glfwWindowHint(GLFW_SAMPLES, 2);
    
    window = glfwCreateWindow(
        WIDTH, HEIGHT, "IT5102E project - Forest", nullptr, nullptr
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
    glfwSetWindowSizeCallback(window, Inputs::instance().windowSizeCallback);
    
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
    //glEnable(GL_MULTISAMPLE);
}

int main() {
    initLibraries();
    
    glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
    
    Scene scene(WIDTH, HEIGHT);
    
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        scene.update();
        
        glfwSwapBuffers(window);
    }
    
    glfwTerminate();
    
    return EXIT_SUCCESS;
}
