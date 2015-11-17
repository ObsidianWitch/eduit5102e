#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>
#include <glm/glm.hpp>

#include "shaders/Shader.hpp"

class Entity {
public:
    Entity(std::string name);
    virtual ~Entity();
    
    virtual void update(Shader& shader);
    virtual void update();
    
protected:
    std::string name;
};

#endif // ENTITY_HPP
