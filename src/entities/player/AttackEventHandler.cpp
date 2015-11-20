#include "entities/player/AttackEventHandler.hpp"

AttackEventHandler::AttackEventHandler() {
    loading = false;
    attacking = false;
}

void AttackEventHandler::keyCallback(
    GLFWwindow*, int key, int, int action, int
) {
    bool state = (action != GLFW_RELEASE);
    
    if (key == GLFW_KEY_SPACE) {
        loading = state;
    }
    else if (key == GLFW_KEY_LEFT_ALT) {
        attacking = state;
    }
}

bool AttackEventHandler::isLoading() { return loading; }
bool AttackEventHandler::isAttacking() { return attacking; }
