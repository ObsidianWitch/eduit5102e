#include "AmbientLight.hpp"

AmbientLight::AmbientLight(std::string name, const glm::vec3& color) :
    Entity(name, glm::vec3(0.0f, 0.0f, 0.0f))
{
    this->color = color;
}

void AmbientLight::update(Shader& shader) {
    shader.setUniform(name + ".color", color);
}
