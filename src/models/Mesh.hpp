#ifndef MESH_HPP
#define MESH_HPP

#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <assimp/mesh.h>

#include "Vertex.hpp"

class Mesh {
public:
    Mesh(const aiMesh* mesh);
    
    void draw();
    
private:
    GLuint vertexArray;
    
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    
    void createBuffers();
};


#endif // MESH_HPP
