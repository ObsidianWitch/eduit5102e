#include "FireRenderer.hpp"

FireRenderer::FireRenderer(BgObject& fire, Camera& camera) :
    fire(fire), camera(camera)
{
    shader.add(GL_VERTEX_SHADER, "src/shaders/fire/fire.vs")
          .add(GL_VERTEX_SHADER, "includes/webgl-noise/classicnoise3D.glsl")
          .add(GL_FRAGMENT_SHADER, "src/shaders/fire/fire.fs")
          .link();
}
    
void FireRenderer::render() {
    shader.use();
    shader.setUniform("time", (float) glfwGetTime());
    
    shader.setUniform("view", camera.getViewMatrix());
    shader.setUniform("projection", camera.getProjectionMatrix());
    
    shader.setUniform("model", fire.getModel().getModelMatrix());
    
    fire.getModel().draw(shader);
}
