#include "entities/lights/PointLight.hpp"

PointLight::PointLight(
    std::string name, const glm::vec3& position, const glm::vec3& color,
    float constant, float linear, float quadratic
) :
    Entity(name)
{
    this->position = position;
    this->color = glm::vec4(color, 1.0f);
    this->constant = constant;
    this->linear = linear;
    this->quadratic = quadratic;
}

void PointLight::update(Shader& shader) {
    shader.setUniform(name + ".position", position);
    shader.setUniform(name + ".color", color);
    shader.setUniform(name + ".constant", constant);
    shader.setUniform(name + ".linear", linear);
    shader.setUniform(name + ".quadratic", quadratic);
}
