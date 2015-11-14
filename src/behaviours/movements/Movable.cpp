#include "behaviours/movements/Movable.hpp"

Movable::Movable(float speed) {
    this->movementVec = glm::vec3(0.0f);
    this->speed = speed;
}

Movable::~Movable() {}
