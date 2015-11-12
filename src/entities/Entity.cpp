#include <cassert>

#include "entities/Entity.hpp"

/**
 * Creates an entity. An entity is any object which can be added to a scene and
 * which can be updated each frame. The name attribute can be used to associate
 * an Entity instance to its counterpart in glsl code.
 */
Entity::Entity(std::string name) {
    this->name = name;
}

/**
 * Updates this Entity's state, and update uniforms linked to this
 * entity with the specified shader. The shader should be bound before
 * calling this method. This method should not be called if it has not been
 * overridden. Overriding this method is optional.
 */
void Entity::update(Shader&) { assert(false); }
