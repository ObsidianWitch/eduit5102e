#ifndef CAMERA_MOUSE_HANDLER
#define CAMERA_MOUSE_HANDLER

#include <glm/glm.hpp>
#include "inputs/MouseHandler.hpp"

class Camera;

class CameraMouseHandler : public MouseHandler {
public:
    CameraMouseHandler(Camera* camera);
    
    void mouseButtonCallback(
        GLFWwindow* window, int button, int action, int mods
    ) override;
    void cursorPositionCallback(
        GLFWwindow* window, double xpos, double ypos
    ) override;
    
private:
    static const double MOUSE_SENSITIVITY;
    
    Camera* camera;
    bool cameraIsMoving;
    glm::dvec2 mousePosition;
};

#endif // CAMERA_MOUSE_HANDLER
