#include "AmbientLight.hpp"

AmbientLight::AmbientLight(std::string name, const glm::vec3& color) :
    Entity(name)
{
    this->color = color;
}

void AmbientLight::update(Shader& shader) {
    shader.setUniform(name + ".color", color);
}
