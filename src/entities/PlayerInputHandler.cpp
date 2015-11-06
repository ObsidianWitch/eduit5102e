#include "Player.hpp"
#include "PlayerInputHandler.hpp"

#include <iostream>

PlayerInputHandler::PlayerInputHandler() {
    keyStates[GLFW_KEY_W] = false;
    keyStates[GLFW_KEY_S] = false;
    keyStates[GLFW_KEY_A] = false;
    keyStates[GLFW_KEY_D] = false;
    
    strafing = false;
}

void PlayerInputHandler::keyCallback(
    GLFWwindow*, int key, int, int action, int
) {
    bool keyState = (action != GLFW_RELEASE);
    
    if (key == GLFW_KEY_W) {
        keyStates[GLFW_KEY_W] = keyState;
    }
    else if (key == GLFW_KEY_S) {
        keyStates[GLFW_KEY_S] = keyState;
    }
    else if (key == GLFW_KEY_A) {
        keyStates[GLFW_KEY_A] = keyState;
    }
    else if (key == GLFW_KEY_D) {
        keyStates[GLFW_KEY_D] = keyState;
    }
}

void PlayerInputHandler::mouseButtonCallback(
    GLFWwindow*, int button, int action, int
) {
    if (button == GLFW_MOUSE_BUTTON_LEFT) {
        strafing = (action == GLFW_PRESS);
    }
}

void PlayerInputHandler::cursorPositionCallback(GLFWwindow*, double, double) {}

void PlayerInputHandler::scrollCallback(GLFWwindow*, double, double) {}

std::map<int, bool>& PlayerInputHandler::getKeyStates() {
    return keyStates;
}

bool PlayerInputHandler::getStrafing() {
    return strafing;
}
