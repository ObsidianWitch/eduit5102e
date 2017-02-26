#include <glm/glm.hpp>

#include "behaviours/collisions/Collidable.hpp"

Collidable::Collidable(const BoundingBox& boundingBox) :
    boundingBox(boundingBox)
{}

bool Collidable::collide(Collidable& b) {
    const auto& box1 = getBoundingBox();
    const auto& box2 = b.getBoundingBox();

    return (
        glm::all(glm::greaterThan(box1.maxPos, box2.minPos)) &&
        glm::all(glm::lessThan(box1.minPos, box2.maxPos))
    );
}

BoundingBox Collidable::getBoundingBox() {
    return boundingBox + getPosition();
}
