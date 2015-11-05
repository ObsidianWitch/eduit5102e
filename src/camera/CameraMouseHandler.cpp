#include "CameraMouseHandler.hpp"
#include "Camera.hpp"

const double CameraMouseHandler::MOUSE_SENSITIVITY = 0.25;

CameraMouseHandler::CameraMouseHandler(Camera* camera) {
    this->camera = camera;
    cameraIsMoving = false;
}

void CameraMouseHandler::mouseButtonCallback(
    GLFWwindow* window, int button, int action, int
) {
    if (button == GLFW_MOUSE_BUTTON_LEFT) {
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

void CameraMouseHandler::cursorPositionCallback(
    GLFWwindow*, double xpos, double ypos
) {
    if (cameraIsMoving) {
        glm::dvec2 oldMousePosition = mousePosition;
        mousePosition = glm::dvec2(xpos, ypos);
        
        glm::vec2 delta = (glm::vec2) glm::dvec2(
            (mousePosition.x - oldMousePosition.x) * MOUSE_SENSITIVITY,
            (oldMousePosition.y - mousePosition.y) * MOUSE_SENSITIVITY
        );
        
        camera->rotate(delta);
    }
}

void CameraMouseHandler::scrollCallback(
    GLFWwindow*, double, double yoffset
) {
    camera->zoom(yoffset);
}
