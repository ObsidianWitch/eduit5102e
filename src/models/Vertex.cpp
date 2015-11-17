#include <GL/glew.h>

#include "models/Vertex.hpp"

Vertex::Vertex(
    const aiVector3D& position, const aiVector3D& normal,
    const aiVector3D& textureCoord, const aiVector3D& tangent,
    const aiVector3D& bitangent
) {
    this->position     = glm::vec3(position.x, position.y, position.z);
    this->normal       = glm::vec3(normal.x, normal.y, normal.z);
    this->textureCoord = glm::vec2(textureCoord.x, textureCoord.y);
    this->tangent      = glm::vec3(tangent.x, tangent.y, tangent.z);
    this->bitangent    = glm::vec3(bitangent.x, bitangent.y, bitangent.z);
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

/**
 * Vertex attribute array at index 2 for vertices texture coordinates, and
 * enables this array.
 */
void Vertex::textureCoordAttribPointer() {
    glVertexAttribPointer(
        2, 2, GL_FLOAT, GL_FALSE, sizeof(Vertex),
        (GLvoid*) offsetof(Vertex, textureCoord)
    );
    glEnableVertexAttribArray(2);
}

/**
 * Vertex attribute array at index 3 for vertices tangents, and enables this
 * array.
 */
void Vertex::tangentAttribPointer() {
    glVertexAttribPointer(
        3, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
        (GLvoid*) offsetof(Vertex, tangent)
    );
    glEnableVertexAttribArray(3);
}

/**
 * Vertex attribute array at index 3 for vertices tangents, and enables this
 * array.
 */
void Vertex::bitangentAttribPointer() {
    glVertexAttribPointer(
        4, 3, GL_FLOAT, GL_FALSE, sizeof(Vertex),
        (GLvoid*) offsetof(Vertex, bitangent)
    );
    glEnableVertexAttribArray(4);
}
