#include "BaseShader.hpp"

BaseShader::BaseShader() {
    shader.add(GL_VERTEX_SHADER, "src/shaders/glsl/base.vs")
          .add(GL_FRAGMENT_SHADER, "src/shaders/glsl/base.frag")
          .link();
    
    modelUniform = shader.uniformLocation("model");
}

void BaseShader::use() {
    shader.use();
}

void BaseShader::updateModelUniform(const glm::mat4& modelMatrix) {
    shader.setUniform(modelUniform, modelMatrix);
}
