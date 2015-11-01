#ifndef SHADERS_HPP
#define SHADERS_HPP

#include <string>
#include <vector>
#include <GL/glew.h>
#include <glm/mat3x3.hpp>
#include <glm/mat4x4.hpp>

class Shader {
public:
    Shader();
    
    Shader& add(GLenum type, std::string filename);
    void link();
    void use();
    
    GLuint uniformLocation(std::string uniformName);
    void setUniform(GLuint id, GLuint value);
    void setUniform(GLuint id, GLfloat value);
    void setUniform(GLuint id, glm::vec3 value);
    void setUniform(GLuint id, glm::mat3 value);
    void setUniform(GLuint id, glm::mat4 value);
    
private:
    std::vector<GLuint> shaders;
    GLuint program;
    
    std::string readShader(std::string filename);
    void compilationErrors(GLint shader);
    void linkageErrors();
};

#endif // SHADERS_HPP
