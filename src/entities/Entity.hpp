#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <glm/glm.hpp>

#include "shaders/Shader.hpp"

class Entity {
public:
    Entity(const glm::vec3& position);
    
    /**
     * Updates this Entity's state, and update uniforms linked to this
     * entity with the specified shader. The shader should be bound before
     * calling this method.
     */
    virtual void update(Shader& shader) = 0;
    
protected:
    glm::vec3 position;
};

#endif // ENTITY_HPP
