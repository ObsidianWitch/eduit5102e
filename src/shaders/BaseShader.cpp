#include "BaseShader.hpp"

BaseShader::BaseShader() {
    add(GL_VERTEX_SHADER, "src/shaders/glsl/base.vs")
    .add(GL_FRAGMENT_SHADER, "src/shaders/glsl/base.fs")
    .link();
    
    setSamplersUniforms();
}

void BaseShader::setSamplersUniforms() {
    use();
    setUniform("diffuseTexture", (GLuint) 0);
}
