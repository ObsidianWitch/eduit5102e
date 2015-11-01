#ifndef MOUSE_HANDLER_HPP
#define MOUSE_HANDLER_HPP

#include <GLFW/glfw3.h>

class MouseHandler {
public:
    virtual ~MouseHandler() {}
    
    virtual void mouseButtonCallback(
        GLFWwindow* window, int button, int action, int mods
    ) = 0;
    virtual void cursorPositionCallback(
        GLFWwindow* window, double xpos, double ypos
    ) = 0;
};

#endif // MOUSE_HANDLER_HPP
