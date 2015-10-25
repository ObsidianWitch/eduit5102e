#ifndef BASE_SHADER_HPP
#define BASE_SHADER_HPP

#include "shaders/Shader.hpp"

class BaseShader {
public:
    BaseShader();
    
    void use();
    
private:
    Shader shader;
};

#endif // BASE_SHADER_HPP
