#include "Collision.hpp"

bool Collision::check(const BoundingBox& box1, const BoundingBox& box2) {
    return (
        glm::all(glm::greaterThan(box1.maxVec, box2.minVec)) &&
        glm::all(glm::lessThan(box1.minVec, box2.maxVec))
    );
}
