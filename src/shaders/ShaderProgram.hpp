#ifndef SHADER_PROGRAM_HPP
#define SHADER_PROGRAM_HPP

#include <string>
#include <vector>
#include <GL/glew.h>
#include <glm/glm.hpp>

class ShaderProgram {
public:
    ShaderProgram();
    
    ShaderProgram& add(GLenum type, std::string filename);
    void link();
    void use();
    
    GLuint uniformLocation(std::string uniformName);
    void setUniform(GLuint id, GLuint value);
    void setUniform(GLuint id, GLfloat value);
    void setUniform(GLuint id, const glm::vec3& value);
    void setUniform(GLuint id, const glm::mat3& value);
    void setUniform(GLuint id, const glm::mat4& value);
    
private:
    std::vector<GLuint> shaders;
    GLuint program;
    
    std::string readShader(std::string filename);
    void compilationErrors(GLint shader);
    void linkageErrors();
};

#endif // SHADER_PROGRAM_HPP
