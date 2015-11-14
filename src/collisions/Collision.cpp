#include "Collision.hpp"

bool Collision::check(const BoundingBox& box1, const BoundingBox& box2) {
    return (
        glm::all(glm::greaterThan(box1.maxPos, box2.minPos)) &&
        glm::all(glm::lessThan(box1.minPos, box2.maxPos))
    );
}
