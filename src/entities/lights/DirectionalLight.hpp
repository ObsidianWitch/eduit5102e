#ifndef DIRECTIONAL_LIGHT_HPP
#define DIRECTIONAL_LIGHT_HPP

#include "entities/Entity.hpp"

class DirectionalLight : public Entity {
public:
    DirectionalLight(
        std::string name, const glm::vec3& direction, const glm::vec3& color
    );
    
    void update(Shader& shader) override;
    
private:
    glm::vec3 direction;
    glm::vec4 color;
};

#endif // DIRECTIONAL_LIGHT_HPP
