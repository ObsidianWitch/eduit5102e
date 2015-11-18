#ifndef POINT_LIGHT_HPP
#define POINT_LIGHT_HPP

#include "entities/Entity.hpp"

class PointLight : public Entity {
public:
    PointLight(
        std::string name, const glm::vec3& position, const glm::vec3& color,
        float constant, float linear, float quadratic
    );
    
    void update(Shader& shader) override;
    
private:
    glm::vec3 position;
    glm::vec4 color;
    
    float constant;
    float linear;
    float quadratic;
};

#endif // POINT_LIGHT_HPP
