#include "entities/Entity.hpp"

/**
 * Creates an entity. An entity is any object which can be added to a scene and
 * which can be updated each frame. The name attribute can be used to associate
 * an Entity instance to its counterpart in glsl code.
 */
Entity::Entity(std::string name) {
    this->name = name;
}
