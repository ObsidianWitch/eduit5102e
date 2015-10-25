#include "BaseShader.hpp"

BaseShader::BaseShader() {
    shader.add(GL_VERTEX_SHADER, "src/shaders/glsl/base.vs")
          .add(GL_FRAGMENT_SHADER, "src/shaders/glsl/base.frag")
          .link();
}

void BaseShader::use() {
    shader.use();
}
