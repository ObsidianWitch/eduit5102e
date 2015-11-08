#include "entities/Entity.hpp"

/**
 * Creates an entity. An entity is any object which can be added to a scene and
 * which can be updated each frame.
 */
Entity::Entity(const glm::vec3& position) {
    this->position = position;
}
