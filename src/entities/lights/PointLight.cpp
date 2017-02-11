#include "entities/lights/PointLight.hpp"

#include <GLFW/glfw3.h>

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
    this->quadFrequency = 4;
}

void PointLight::update(Shader& shader) {
    // quadOverTime in [1.0 ; 3.0]
    auto quadOverTime = (float) sin(
        quadFrequency * glfwGetTime()
    ) + 2.0f;

    shader.setUniform(name + ".position", position);
    shader.setUniform(name + ".color", color);
    shader.setUniform(name + ".constant", constant);
    shader.setUniform(name + ".linear", linear);
    shader.setUniform(name + ".quadratic", quadratic * quadOverTime);
}
