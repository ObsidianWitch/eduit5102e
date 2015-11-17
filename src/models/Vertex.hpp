#ifndef VERTEX_HPP
#define VERTEX_HPP

#include <glm/glm.hpp>
#include <assimp/mesh.h>

struct Vertex {
    glm::vec3 position;
    glm::vec3 normal;
    glm::vec2 textureCoord;
    glm::vec3 tangent;
    glm::vec3 bitangent;
    
    Vertex(
        const aiVector3D& position, const aiVector3D& normal,
        const aiVector3D& textureCoord, const aiVector3D& tangent,
        const aiVector3D& bitangent
    );
    
    static void positionAttribPointer();
    static void normalAttribPointer();
    static void textureCoordAttribPointer();
    static void tangentAttribPointer();
    static void bitangentAttribPointer();
};

#endif // VERTEX_HPP
