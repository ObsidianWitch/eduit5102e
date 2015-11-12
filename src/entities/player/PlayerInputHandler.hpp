#ifndef PLAYER_INPUT_HANDLER
#define PLAYER_INPUT_HANDLER

#include <map>

#include "inputs/KeyHandler.hpp"
#include "inputs/MouseHandler.hpp"

enum Movements {
    FORWARD, BACKWARD, LEFT, RIGHT
};

class PlayerInputHandler : public KeyHandler, public MouseHandler {
public:
    PlayerInputHandler();
    
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

#endif // PLAYER_INPUT_HANDLER
