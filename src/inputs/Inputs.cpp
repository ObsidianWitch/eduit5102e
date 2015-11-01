#include "Inputs.hpp"

std::vector<KeyHandler*> Inputs::keyHandlers;
std::vector<MouseHandler*> Inputs::mouseHandlers;

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


void Inputs::mouseButtonCallback(
    GLFWwindow* window, int button, int action, int mods
) {
    for (MouseHandler* mh : mouseHandlers) {
        mh->mouseButtonCallback(window, button, action, mods);
    }
}

void Inputs::cursorPositionCallback(
    GLFWwindow* window, double xpos, double ypos
) {
    for (MouseHandler* mh : mouseHandlers) {
        mh->cursorPositionCallback(window, xpos, ypos);
    }
}

void Inputs::addMouseHandler(MouseHandler& mh) {
    mouseHandlers.push_back(&mh);
}
