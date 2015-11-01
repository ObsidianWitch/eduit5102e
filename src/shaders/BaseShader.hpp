#ifndef BASE_SHADER_HPP
#define BASE_SHADER_HPP

#include "shaders/ShaderProgram.hpp"

class BaseShader {
public:
    BaseShader();
    
    void use();
    
    void updateModelUniform(const glm::mat4& modelMatrix);
    
private:
    ShaderProgram shader;
    GLint modelUniform;
};

#endif // BASE_SHADER_HPP
