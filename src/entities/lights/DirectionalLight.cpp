#include "DirectionalLight.hpp"

DirectionalLight::DirectionalLight(
    const glm::vec3& direction, const glm::vec3& color
) :
    Entity(glm::vec3(0.0f, 0.0f, 0.0f))
{
    this->direction = direction;
    this->color = color;
}

void DirectionalLight::update(Shader& shader) {
    shader.setUniform("dL.direction", direction);
    shader.setUniform("dL.color", color);
}
