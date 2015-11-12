#ifndef WINDOW_HANDLER_HPP
#define WINDOW_HANDLER_HPP

#include <GLFW/glfw3.h>

class WindowHandler {
public:
    virtual ~WindowHandler() {}
    
    virtual void windowSizeCallback(
        GLFWwindow* window, int width, int height
    ) = 0;
};

#endif // WINDOW_HANDLER_HPP
