#include "entities/player/Player.hpp"
#include "entities/player/PlayerEventHandler.hpp"

#include <iostream>

PlayerEventHandler::PlayerEventHandler() {
    for (int mvt = FORWARD ; mvt <= RIGHT ; mvt++) {
        states[mvt] = false;
    }
    
    strafing = false;
}

void PlayerEventHandler::keyCallback(
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

void PlayerEventHandler::mouseButtonCallback(
    GLFWwindow*, int button, int action, int
) {
    if (button == GLFW_MOUSE_BUTTON_RIGHT) {
        strafing = (action == GLFW_PRESS);
    }
}

void PlayerEventHandler::cursorPositionCallback(GLFWwindow*, double, double) {}

void PlayerEventHandler::scrollCallback(GLFWwindow*, double, double) {}

bool PlayerEventHandler::isDiagonal() {
    return (states[FORWARD] || states[BACKWARD])
        && (states[LEFT] || states[RIGHT]);
}

std::map<int, bool>& PlayerEventHandler::getStates() { return states; }
bool PlayerEventHandler::getStrafing() { return strafing; }
