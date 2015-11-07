#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <glm/glm.hpp>
#include <assimp/mesh.h>

struct Vertex {
    Vertex(const aiVector3D& position, const aiVector3D& normal);
    
    glm::vec3 position;
    glm::vec3 normal;
};

#endif // VERTEX_HPP
