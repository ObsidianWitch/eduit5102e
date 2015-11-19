#include <glm/gtx/rotate_vector.hpp>

#include "WaterfallRenderer.hpp"

WaterfallRenderer::WaterfallRenderer(
    BgObject& waterfall, Camera& camera,
    std::vector<std::shared_ptr<Entity>>& lights
) :
    waterfall(waterfall), camera(camera)
{
    shader.add(GL_VERTEX_SHADER, "src/shaders/main/main.vs")
          .add(GL_FRAGMENT_SHADER, "src/shaders/main/main.fs")
          .add(GL_FRAGMENT_SHADER, "src/shaders/waterfall/texture.fs")
          .add(GL_FRAGMENT_SHADER, "src/shaders/main/phong.fs")
          .add(GL_FRAGMENT_SHADER, "src/shaders/main/lights.fs")
          .link();
    
    shader.use();
    for (auto l : lights) { l->update(shader); }
}
    
void WaterfallRenderer::render() {
    shader.use();
    shader.setUniform("time", (float) glfwGetTime());
    
    shader.setUniform("view", camera.getViewMatrix());
    shader.setUniform("projection", camera.getProjectionMatrix());
    shader.setUniform("cameraPosition", camera.getPosition());
    
    shader.setUniform("model", waterfall.getModel().getModelMatrix());
    shader.setUniform("normalMatrix", waterfall.getModel().getNormalMatrix());
    
    waterfall.getModel().draw(shader);
}
