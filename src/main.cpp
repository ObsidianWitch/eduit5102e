#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "Object3D.hpp"
#include "Shader.hpp"

const GLuint WIDTH = 800;
const GLuint HEIGHT = 600;

GLFWwindow* window = nullptr;

void error_callback(int, const char* description) {
	std::cerr << description << std::endl;
}

void key_callback(
    GLFWwindow* window, int key, int, int action, int
) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
}

/**
 * Initializes GLFW (window & callbacks), GLEW (extensions), and some OpenGL
 * features.
 */
void initLibraries() {
    // GLFW
    glfwSetErrorCallback(error_callback);
    
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
    
    glfwSetKeyCallback(window, key_callback);
    
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
    Object3D obj("resources/apple.obj");
    Shader baseShader("src/shaders/base.vs", "src/shaders/base.frag");
    
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
        
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        
        baseShader.use();
        obj.draw();
        
        glfwSwapBuffers(window);
    }
    
    terminate();
    
    return EXIT_SUCCESS;
}
