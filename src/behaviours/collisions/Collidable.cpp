#include <glm/glm.hpp>

#include "behaviours/collisions/Collidable.hpp"
#include "behaviours/collisions/Collision.hpp"

Collidable::Collidable(const BoundingBox& boundingBox) :
    boundingBox(boundingBox)
{}

bool Collidable::collide(Collidable& b) {
    return Collision::check(getBoundingBox(), b.getBoundingBox());
}

BoundingBox Collidable::getBoundingBox() {
    return boundingBox + getPosition();
}
