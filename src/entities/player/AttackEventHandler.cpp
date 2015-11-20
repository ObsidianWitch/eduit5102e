#include "entities/player/AttackEventHandler.hpp"

AttackEventHandler::AttackEventHandler() {
    attacking = false;
}

void AttackEventHandler::keyCallback(
    GLFWwindow*, int key, int, int action, int
) {
    bool state = (action != GLFW_RELEASE);
    
    if (key == GLFW_KEY_SPACE) {
        attacking = state;
    }
}

bool AttackEventHandler::isAttacking() { return attacking; }
