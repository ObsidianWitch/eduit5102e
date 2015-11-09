#ifndef AMBIENT_LIGHT_HPP
#define AMBIENT_LIGHT_HPP

#include "entities/Entity.hpp"

class AmbientLight : public Entity {
public:
    AmbientLight(std::string name, const glm::vec3& color);
    
    void update(Shader& shader) override;
    
private:
    glm::vec3 color;
};

#endif // AMBIENT_LIGHT_HPP
