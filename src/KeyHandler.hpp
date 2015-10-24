#ifndef KEY_HANDLER_HPP
#define KEY_HANDLER_HPP

#include <GLFW/glfw3.h>

class KeyHandler {
public:
    virtual ~KeyHandler() {}
    
    virtual void keyCallback(
        GLFWwindow* window, int key, int scancode, int action, int mods
    ) = 0;
};

#endif // KEY_HANDLER_HPP
