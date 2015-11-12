#ifndef CAMERA_WINDOW_HANDLER
#define CAMERA_WINDOW_HANDLER

#include "inputs/WindowHandler.hpp"

class Camera;

class CameraWindowHandler : public WindowHandler {
public:
    CameraWindowHandler(Camera* camera);
    
    void windowSizeCallback(
        GLFWwindow* window, int width, int height
    ) override;
    
private:
    Camera* camera;
};

#endif // CAMERA_WINDOW_HANDLER
