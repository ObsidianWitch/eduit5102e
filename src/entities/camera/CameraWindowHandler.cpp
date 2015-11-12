#include "entities/camera/Camera.hpp"
#include "entities/camera/CameraWindowHandler.hpp"

CameraWindowHandler::CameraWindowHandler(Camera* camera) {
    this->camera = camera;
}

void CameraWindowHandler::windowSizeCallback(
    GLFWwindow*, int width, int height
) {
    camera->setViewport(width, height);
}
