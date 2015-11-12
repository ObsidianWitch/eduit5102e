#ifndef INPUTS_HPP
#define INPUTS_HPP

#include <vector>
#include <GLFW/glfw3.h>
#include "inputs/KeyHandler.hpp"
#include "inputs/MouseHandler.hpp"

class Inputs {
public:
    static Inputs& instance();
    
    static void keyCallback(
        GLFWwindow* window, int key, int scancode, int action, int mods
    );
    static void addKeyHandler(KeyHandler& kh);
    
    static void mouseButtonCallback(
        GLFWwindow* window, int button, int action, int mods
    );
    static void cursorPositionCallback(
        GLFWwindow* window, double xpos, double ypos
    );
    static void scrollCallback(
        GLFWwindow* window, double xoffset, double yoffset
    );
    static void addMouseHandler(MouseHandler& mh);

private:
    static std::vector<KeyHandler*> keyHandlers;
    static std::vector<MouseHandler*> mouseHandlers;
    
    Inputs(); // prevent more than one instance
    Inputs(Inputs const&); // prevent copies
    void operator=(Inputs const&); // prevent assignments
};

#endif // INPUTS_HPP
