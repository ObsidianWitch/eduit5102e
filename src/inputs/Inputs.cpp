#include "inputs/Inputs.hpp"

std::vector<KeyHandler*> Inputs::keyHandlers;
std::vector<MouseHandler*> Inputs::mouseHandlers;
std::vector<WindowHandler*> Inputs::windowHandlers;

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

    for (auto* kh : keyHandlers) {
        kh->keyCallback(window, key, scancode, action, mods);
    }
}

void Inputs::addKeyHandler(KeyHandler& kh) {
    keyHandlers.push_back(&kh);
}


void Inputs::mouseButtonCallback(
    GLFWwindow* window, int button, int action, int mods
) {
    for (auto* mh : mouseHandlers) {
        mh->mouseButtonCallback(window, button, action, mods);
    }
}

void Inputs::cursorPositionCallback(
    GLFWwindow* window, double xpos, double ypos
) {
    for (auto* mh : mouseHandlers) {
        mh->cursorPositionCallback(window, xpos, ypos);
    }
}

void Inputs::scrollCallback(
    GLFWwindow* window, double xoffset, double yoffset
) {
    for (auto* mh : mouseHandlers) {
        mh->scrollCallback(window, xoffset, yoffset);
    }
}

void Inputs::addMouseHandler(MouseHandler& mh) {
    mouseHandlers.push_back(&mh);
}


void Inputs::windowSizeCallback(GLFWwindow* window, int width, int height) {
    for (auto* wh : windowHandlers) {
        wh->windowSizeCallback(window, width, height);
    }
}

void Inputs::addWindowHandler(WindowHandler& wh) {
    windowHandlers.push_back(&wh);
}
