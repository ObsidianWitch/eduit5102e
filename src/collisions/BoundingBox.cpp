#include "BoundingBox.hpp"

/**
 * Instantiates an Axis Aligned Bounding Box (AABB). An AABB is a nonrotatable
 * box whose edges are parallel to the axes of the scene.
 */
BoundingBox::BoundingBox(const glm::vec3& minVec, const glm::vec3& maxVec) {
    this->minVec = minVec;
    this->maxVec = maxVec;
}

BoundingBox BoundingBox::operator+(const glm::vec3& vec) {
    return BoundingBox(
        minVec + vec,
        maxVec + vec
    );
}
