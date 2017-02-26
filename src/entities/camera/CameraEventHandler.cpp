#include "entities/camera/Camera.hpp"
#include "entities/camera/CameraEventHandler.hpp"

const double CameraEventHandler::MOUSE_SENSITIVITY = 0.25;

CameraEventHandler::CameraEventHandler(Camera* camera) {
    this->camera = camera;
    cameraIsMoving = false;
}

void CameraEventHandler::mouseButtonCallback(
    GLFWwindow* window, int button, int action, int
) {
    if (button == GLFW_MOUSE_BUTTON_LEFT || button == GLFW_MOUSE_BUTTON_RIGHT) {
        if (action == GLFW_PRESS) {
            cameraIsMoving = true;
            glfwGetCursorPos(window, &mousePosition.x, &mousePosition.y);
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);
        }
        else {
            cameraIsMoving = false;
            glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);
        }
    }
}

void CameraEventHandler::cursorPositionCallback(
    GLFWwindow*, double xpos, double ypos
) {
    if (!cameraIsMoving) { return; }

    auto oldMousePosition = mousePosition;
    mousePosition = glm::dvec2(xpos, ypos);

    auto delta = (glm::vec2) glm::dvec2(
        (oldMousePosition.x - mousePosition.x) * MOUSE_SENSITIVITY,
        (mousePosition.y - oldMousePosition.y) * MOUSE_SENSITIVITY
    );

    camera->rotate(delta);
}

void CameraEventHandler::scrollCallback(
    GLFWwindow*, double, double yoffset
) {
    camera->zoom(yoffset);
}

void CameraEventHandler::windowSizeCallback(
    GLFWwindow*, int width, int height
) {
    camera->setViewport(width, height);
}
