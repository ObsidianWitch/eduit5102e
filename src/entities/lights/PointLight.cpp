#include "entities/lights/PointLight.hpp"

PointLight::PointLight(
    std::string name, const glm::vec3& position, const glm::vec3& color
) :
    Entity(name)
{
    this->position = position;
    this->color = glm::vec4(color, 1.0f);
}

void PointLight::update(Shader& shader) {
    shader.setUniform(name + ".position", position);
    shader.setUniform(name + ".color", color);
}
