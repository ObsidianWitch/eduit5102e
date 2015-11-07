#include <GL/glew.h>

#include "Vertex.hpp"

Vertex::Vertex(const aiVector3D& position, const aiVector3D& normal) {
    this->position = glm::vec3(position.x, position.y, position.z);
    this->normal = glm::vec3(normal.x, normal.y, normal.z);
}

/**
 * Vertex attribute array at index 0 for vertices positions, and enables this
 * array.
 */
void Vertex::positionAttribPointer() {
    glVertexAttribPointer(
        0, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
        (GLvoid*) offsetof(Vertex, position)
    );
    glEnableVertexAttribArray(0);
}

/**
 * Vertex attribute array at index 1 for vertices normals, and enables this
 * array.
 */
void Vertex::normalAttribPointer() {
    glVertexAttribPointer(
        1, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
        (GLvoid*) offsetof(Vertex, normal)
    );
    glEnableVertexAttribArray(1);
}
