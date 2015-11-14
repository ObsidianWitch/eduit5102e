#include "BoundingBox.hpp"

/**
 * Instantiates an Axis Aligned Bounding Box (AABB). An AABB is a nonrotatable
 * box whose edges are parallel to the axes of the scene.
 */
BoundingBox::BoundingBox(const glm::vec3& minPos, const glm::vec3& maxPos) {
    this->minPos = minPos;
    this->maxPos = maxPos;
}

BoundingBox BoundingBox::operator+(const glm::vec3& vec) {
    return BoundingBox(
        minPos + vec,
        maxPos + vec
    );
}
