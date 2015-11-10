#include "PointLight.hpp"

PointLight::PointLight(
    std::string name, const glm::vec3& position, const glm::vec3& color
) :
    Entity(name, position)
{
    this->color = color;
}

void PointLight::update(Shader& shader) {
    shader.setUniform(name + ".position", position);
    shader.setUniform(name + ".color", color);
}
