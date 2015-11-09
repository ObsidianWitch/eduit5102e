#include "DirectionalLight.hpp"

DirectionalLight::DirectionalLight(
    std::string name, const glm::vec3& direction, const glm::vec3& color
) :
    Entity(name, glm::vec3(0.0f, 0.0f, 0.0f))
{
    this->direction = direction;
    this->color = color;
}

void DirectionalLight::update(Shader& shader) {
    shader.setUniform(name + ".direction", direction);
    shader.setUniform(name + ".color", color);
}
