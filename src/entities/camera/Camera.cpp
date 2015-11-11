#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/rotate_vector.hpp>
#include <cmath>

#include "tools/LocalBasis.hpp"
#include "entities/camera/Camera.hpp"

const float Camera::MIN_PITCH = -80.0f;
const float Camera::MAX_PITCH = 60.0f;
const float Camera::MIN_ZOOM  = 5.0f;
const float Camera::MAX_ZOOM  = 30.0f;

/**
 * Creates a perspective Camera which holds the view & projection matrices. In
 * order to create these matrices, we need the following parameters.
 * @param position Position of the camera.
 * @param target Camera's target.
 * @param targetOffset
 * @param fov Fielf of view (radians).
 * @param width Used to compute the aspect ratio (width/height).
 * @param height Used to compute the aspect ratio (width/height).
 * @param zNear Distance from the camera to the near clipping plane.
 * @param zFar Distance from the camera to the far clipping plane.
 */
Camera::Camera(
    const glm::vec3& position, const glm::vec3& target,
    const glm::vec3& targetOffset,
    float fov, float width, float height, float zNear, float zFar
) :
    Entity("camera"),
    cameraMouseHandler(this)
{
    this->position = position;
    this->target = target + targetOffset;
    this-> targetOffset = targetOffset;
    
    this->fov = fov;
    this->width = width;
    this->height = height;
    this->zNear = zNear;
    this->zFar = zFar;
}

void Camera::translate(const glm::vec3& vec) {
    position += vec;
}

void Camera::rotate(float angle, const glm::vec3& axis) {
    position = glm::rotate(position, angle, axis);
    target = glm::rotate(target, angle, axis);
}

void Camera::rotate(const glm::vec2& delta) {
    rotate(glm::radians(delta.x), getUp()); // yaw
    
    float pitch = glm::degrees(std::asin(getDirection().y)) + delta.y;
    if (pitch > MIN_PITCH && pitch < MAX_PITCH) {
        rotate(glm::radians(delta.y), getRight());
    }
}

void Camera::zoom(float value) {
    glm::vec3 deltaZoom = getDirection() * value;
    float distanceToTarget = glm::distance(position + deltaZoom, target);
    
    if (distanceToTarget > MIN_ZOOM && distanceToTarget < MAX_ZOOM) {
        position += deltaZoom;
    }
}


void Camera::update(Shader& shader, const glm::vec3& newTarget) {
    translate(newTarget + targetOffset - target);
    target = newTarget + targetOffset;
    
    update(shader);
}

void Camera::update(Shader& shader) {
    shader.setUniform("view", getViewMatrix());
    shader.setUniform("projection", getProjectionMatrix());
    shader.setUniform("cameraPosition", position);
}

glm::mat4 Camera::getViewMatrix() {
    return glm::lookAt(position, target, getUp());
}

glm::mat4 Camera::getProjectionMatrix() {
    return glm::perspectiveFov(fov, width, height, zNear, zFar);
}

glm::vec3 Camera::getDirection() {
    return glm::normalize(target - position);
}

glm::vec3 Camera::getRight() {
    return glm::normalize(glm::cross(getDirection(), LocalBasis::y));
}

glm::vec3 Camera::getUp() {
    return glm::normalize(glm::cross(getRight(), getDirection()));
}

float Camera::getWidth() { return width; }
float Camera::getHeight() { return height; }

MouseHandler& Camera::getMouseHandler() {
    return cameraMouseHandler;
}
