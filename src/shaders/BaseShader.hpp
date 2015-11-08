#ifndef BASE_SHADER_HPP
#define BASE_SHADER_HPP

#include "shaders/ShaderProgram.hpp"

class BaseShader {
public:
    BaseShader();
    
    void use();
    
    void updateModelUniform(const glm::mat4& modelMatrix);
    void updateViewUniform(const glm::mat4& viewMatrix);
    void updateProjectionUniform(const glm::mat4& projectionMatrix);
    
private:
    ShaderProgram shader;
    GLint modelUniform;
    GLint viewUniform;
    GLint projectionUniform;
    
    void setSamplersUniforms();
};

#endif // BASE_SHADER_HPP
