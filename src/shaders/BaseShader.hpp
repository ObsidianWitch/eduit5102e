#ifndef BASE_SHADER_HPP
#define BASE_SHADER_HPP

#include "shaders/ShaderProgram.hpp"

class BaseShader {
public:
    BaseShader();
    
    void use();
    
private:
    ShaderProgram shader;
};

#endif // BASE_SHADER_HPP
