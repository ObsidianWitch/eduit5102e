#include "entities/lights/AmbientLight.hpp"

AmbientLight::AmbientLight(std::string name, const glm::vec3& color) :
    Entity(name)
{
    this->color = glm::vec4(color, 1.0f);
}

void AmbientLight::update(Shader& shader) {
    shader.setUniform(name + ".color", color);
}
