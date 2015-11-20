#ifndef ATTACK_EVENT_HANDLER
#define ATTACK_EVENT_HANDLER

#include <map>

#include "inputs/KeyHandler.hpp"

class AttackEventHandler : public KeyHandler {
public:
    AttackEventHandler();
    
    void keyCallback(
        GLFWwindow* window, int key, int scancode, int action, int mods
    ) override;
    
    bool isAttacking();
    
private:
    bool attacking;
};

#endif // ATTACK_EVENT_HANDLER
