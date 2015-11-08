#ifndef BASE_SHADER_HPP
#define BASE_SHADER_HPP

#include "shaders/Shader.hpp"

class BaseShader : public Shader {
public:
    BaseShader();
    
private:
    void setSamplersUniforms();
};

#endif // BASE_SHADER_HPP
