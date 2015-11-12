#ifndef CAMERA_EVENT_HANDLER
#define CAMERA_EVENT_HANDLER

#include <glm/glm.hpp>
#include "inputs/MouseHandler.hpp"
#include "inputs/WindowHandler.hpp"

class Camera;

class CameraEventHandler : public MouseHandler, public WindowHandler {
public:
    CameraEventHandler(Camera* camera);
    
    void mouseButtonCallback(
        GLFWwindow* window, int button, int action, int mods
    ) override;
    void cursorPositionCallback(
        GLFWwindow* window, double xpos, double ypos
    ) override;
    void scrollCallback(
        GLFWwindow* window, double xoffset, double yoffset
    ) override;
    
    void windowSizeCallback(
        GLFWwindow* window, int width, int height
    ) override;
    
private:
    static const double MOUSE_SENSITIVITY;
    
    Camera* camera;
    bool cameraIsMoving;
    glm::dvec2 mousePosition;
};

#endif // CAMERA_EVENT_HANDLER
