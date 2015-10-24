#ifndef MESH_HPP
#define MESH_HPP

#include <vector>
#include <GL/glew.h>
#include <glm/vec3.hpp>
#include "Shader.hpp"

class Mesh {
public:
    Mesh();
    Mesh(
        std::vector<glm::vec3> vertices, std::vector<glm::vec3> normals,
        std::vector<GLuint> indices
    );
    void initialize(
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
