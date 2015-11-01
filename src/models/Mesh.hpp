#ifndef MESH_HPP
#define MESH_HPP

#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>
#include <assimp/mesh.h>

class Mesh {
public:
    Mesh(const aiMesh* mesh);
    Mesh(
        std::vector<glm::vec3> vertices, std::vector<glm::vec3> normals,
        std::vector<GLuint> indices
    );
    
    void draw();
    
private:
    GLuint vertexArray;
    GLuint vertexBuffer;
    GLuint normalBuffer;
    GLuint indexBuffer;
    
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec3> normals;
    std::vector<GLuint> indices;
    
    void createBuffers();
};


#endif // MESH_HPP
