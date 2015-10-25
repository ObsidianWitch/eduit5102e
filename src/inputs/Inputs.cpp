#include "Inputs.hpp"

std::vector<KeyHandler*> Inputs::keyHandlers;

Inputs::Inputs() {}

Inputs& Inputs::instance() {
    static Inputs instance;
    return instance;
}

void Inputs::keyCallback(
    GLFWwindow* window, int key, int scancode, int action, int mods
) {
    if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) {
        glfwSetWindowShouldClose(window, GL_TRUE);
    }
    
    for (KeyHandler* kh : keyHandlers) {
        kh->keyCallback(window, key, scancode, action, mods);
    }
}

void Inputs::addKeyHandler(KeyHandler& kh) {
    keyHandlers.push_back(&kh);
}
