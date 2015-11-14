#include "entities/player/Player.hpp"
#include "entities/player/PlayerInputHandler.hpp"

#include <iostream>

PlayerInputHandler::PlayerInputHandler() {
    for (int mvt = FORWARD ; mvt <= RIGHT ; mvt++) {
        states[mvt] = false;
    }
    
    strafing = false;
}

void PlayerInputHandler::keyCallback(
    GLFWwindow*, int key, int, int action, int
) {
    bool state = (action != GLFW_RELEASE);
    
    if (key == GLFW_KEY_W) {
        states[FORWARD] = state;
    }
    else if (key == GLFW_KEY_S) {
        states[BACKWARD] = state;
    }
    else if (key == GLFW_KEY_A) {
        states[LEFT] = state;
    }
    else if (key == GLFW_KEY_D) {
        states[RIGHT] = state;
    }
}

void PlayerInputHandler::mouseButtonCallback(
    GLFWwindow*, int button, int action, int
) {
    if (button == GLFW_MOUSE_BUTTON_RIGHT) {
        strafing = (action == GLFW_PRESS);
    }
}

void PlayerInputHandler::cursorPositionCallback(GLFWwindow*, double, double) {}

void PlayerInputHandler::scrollCallback(GLFWwindow*, double, double) {}

bool PlayerInputHandler::isDiagonal() {
    return (states[FORWARD] || states[BACKWARD])
        && (states[LEFT] || states[RIGHT]);
}

std::map<int, bool>& PlayerInputHandler::getStates() { return states; }
bool PlayerInputHandler::getStrafing() { return strafing; }
