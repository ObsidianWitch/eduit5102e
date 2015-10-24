#ifndef INPUTS_HPP
#define INPUTS_HPP

#include <vector>
#include <GLFW/glfw3.h>
#include "KeyHandler.hpp"

class Inputs {
public:
    static Inputs& instance();
    
    static void keyCallback(
        GLFWwindow* window, int key, int scancode, int action, int mods
    );
    static void addKeyHandler(KeyHandler& kh);

private:
    static std::vector<KeyHandler*> keyHandlers;
    
    Inputs(); // prevent more than one instance
    Inputs(Inputs const&); // prevent copies
    void operator=(Inputs const&); // prevent assignments
};

#endif // INPUTS_HPP
