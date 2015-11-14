#ifndef PLAYER_EVENT_HANDLER
#define PLAYER_EVENT_HANDLER

#include <map>

#include "inputs/KeyHandler.hpp"
#include "inputs/MouseHandler.hpp"

enum Movements {
    FORWARD, BACKWARD, LEFT, RIGHT
};

class PlayerEventHandler : public KeyHandler, public MouseHandler {
public:
    PlayerEventHandler();
    
    void keyCallback(
        GLFWwindow* window, int key, int scancode, int action, int mods
    ) override;
    
    void mouseButtonCallback(
        GLFWwindow* window, int button, int action, int mods
    ) override;
    void cursorPositionCallback(
        GLFWwindow* window, double xpos, double ypos
    ) override;
    void scrollCallback(
        GLFWwindow* window, double xoffset, double yoffset
    ) override;
    
    bool isDiagonal();
    std::map<int, bool>& getStates();
    bool getStrafing();
    
private:
    std::map<int, bool> states;
    bool strafing;
};

#endif // PLAYER_EVENT_HANDLER
