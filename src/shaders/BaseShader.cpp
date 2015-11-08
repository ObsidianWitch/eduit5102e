#include "BaseShader.hpp"

BaseShader::BaseShader() {
    shader.add(GL_VERTEX_SHADER, "src/shaders/glsl/base.vs")
          .add(GL_FRAGMENT_SHADER, "src/shaders/glsl/base.frag")
          .link();
    
    modelUniform = shader.uniformLocation("model");
    viewUniform = shader.uniformLocation("view");
    projectionUniform = shader.uniformLocation("projection");
    
    setSamplersUniforms();
}

void BaseShader::use() {
    shader.use();
}

void BaseShader::updateModelUniform(const glm::mat4& modelMatrix) {
    shader.setUniform(modelUniform, modelMatrix);
}

void BaseShader::updateViewUniform(const glm::mat4& viewMatrix) {
    shader.setUniform(viewUniform, viewMatrix);
}

void BaseShader::updateProjectionUniform(const glm::mat4& projectionMatrix) {
    shader.setUniform(projectionUniform, projectionMatrix);
}

void BaseShader::setSamplersUniforms() {
    use();
    
    GLuint diffuseTextureUniform = shader.uniformLocation("diffuseTexture");
    shader.setUniform(diffuseTextureUniform, (GLuint) 0);
}
