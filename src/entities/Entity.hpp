#ifndef ENTITY_HPP
#define ENTITY_HPP

#include <string>
#include <glm/glm.hpp>

#include "shaders/Shader.hpp"

class Entity {
public:
    Entity(std::string name);
    
    virtual void update(Shader& shader);
    
protected:
    std::string name;
};

#endif // ENTITY_HPP
