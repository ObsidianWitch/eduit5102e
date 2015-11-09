#include "BaseShader.hpp"

BaseShader::BaseShader() {
    add(GL_VERTEX_SHADER, "src/shaders/glsl/base.vs")
    .add(GL_FRAGMENT_SHADER, "src/shaders/glsl/base.fs")
    .add(GL_FRAGMENT_SHADER, "src/shaders/glsl/illumination.fs")
    .link();
}
