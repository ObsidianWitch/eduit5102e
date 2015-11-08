#ifndef MESH_HPP
#define MESH_HPP

#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <assimp/mesh.h>

#include "Vertex.hpp"
#include "Texture.hpp"

class Mesh {
public:
    Mesh(const aiMesh* mesh, const aiMaterial* material, std::string directory);
    
    void draw();
    
private:
    GLuint vertexArray;
        
    std::vector<Vertex> vertices;
    std::vector<GLuint> indices;
    std::vector<Texture> textures;
    
    void createBuffers();
};


#endif // MESH_HPP
