#ifndef CAMERA_HPP
#define CAMERA_HPP

#include <glm/glm.hpp>
#include "entities/Entity.hpp"
#include "entities/camera/CameraEventHandler.hpp"

class Camera : public Entity {
public:
    Camera(
        const glm::vec3& position, const glm::vec3& target,
        const glm::vec3& targetOffset,
        float fov, float width, float height, float zNear, float zFar
    );
    
    void translate(const glm::vec3& vec);
    void rotate(float angle, const glm::vec3& axis);
    void rotate(const glm::vec2& delta);
    void zoom(float value);
    
    glm::mat4 getViewMatrix();
    glm::mat4 getNonTranslatedViewMatrix();
    glm::mat4 getProjectionMatrix();
    glm::vec3 getPosition();
    CameraEventHandler& getEventHandler();
    
    void setTarget(const glm::vec3& target);
    void setViewport(int width, int height);
    
private:
    CameraEventHandler cameraEventHandler;
    
    // View
    static const float MIN_PITCH;
    static const float MAX_PITCH;
    static const float MIN_ZOOM;
    static const float MAX_ZOOM;
    
    glm::vec3 position;
    glm::vec3 target;
    glm::vec3 targetOffset;
    
    glm::vec3 getDirection();
    glm::vec3 getRight();
    glm::vec3 getUp();
    
    // Projection
    float fov;
    float width;
    float height;
    float zNear;
    float zFar;
};

#endif // CAMERA_HPP
