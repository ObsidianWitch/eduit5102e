#include "Vertex.hpp"

Vertex::Vertex(const aiVector3D& position, const aiVector3D& normal) {
    this->position = glm::vec3(position.x, position.y, position.z);
    this->normal = glm::vec3(normal.x, normal.y, normal.z);
}
