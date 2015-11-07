#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <glm/glm.hpp>
#include <assimp/mesh.h>

struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    
    Vertex(const aiVector3D& position, const aiVector3D& normal);
    
    static void positionAttribPointer();
    static void normalAttribPointer();
};

#endif // VERTEX_HPP
