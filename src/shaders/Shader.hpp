#ifndef SHADER_HPP
#define SHADER_HPP

#include <string>
#include <vector>
#include <unordered_map>
#include <GL/glew.h>
#include <glm/glm.hpp>

class Shader {
public:
    Shader();
    
    Shader& add(GLenum type, std::string filename);
    void link();
    void use();
    
    GLuint uniformLocation(std::string name);
    void setUniform(std::string name, bool value);
    void setUniform(std::string name, GLuint value);
    void setUniform(std::string name, GLfloat value);
    void setUniform(std::string name, const glm::vec3& value);
    void setUniform(std::string name, const glm::vec4& value);
    void setUniform(std::string name, const glm::mat3& value);
    void setUniform(std::string name, const glm::mat4& value);
    
private:
    std::vector<GLuint> shaders;
    GLuint program;
    std::unordered_map<std::string, GLuint> uniformsMap;
    
    std::string readShader(std::string filename);
    void compilationErrors(GLint shader);
    void linkageErrors();
};

#endif // SHADER_HPP
