#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <glm/glm.hpp>
#include <assimp/mesh.h>

struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 textureCoord;
    
    Vertex(
        const aiVector3D& position, const aiVector3D& normal,
        const aiVector3D& textureCoord
    );
    
    static void positionAttribPointer();
    static void normalAttribPointer();
    static void textureCoordAttribPointer();
};

#endif // VERTEX_HPP
