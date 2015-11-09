#include "AmbientLight.hpp"

AmbientLight::AmbientLight(const glm::vec3& color) :
    Entity(glm::vec3(0.0f, 0.0f, 0.0f))
{
    this->color = color;
}

void AmbientLight::update(Shader& shader) {
    shader.setUniform("aL.color", color);
}
