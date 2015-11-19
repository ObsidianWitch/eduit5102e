#include <glm/gtx/rotate_vector.hpp>

#include "StreamRenderer.hpp"

StreamRenderer::StreamRenderer(
    BgObject& river, BgObject& waterfall, Camera& camera,
    std::vector<std::shared_ptr<Entity>>& lights
) :
    river(river), waterfall(waterfall), camera(camera), lights(lights)
{
    shader.add(GL_VERTEX_SHADER, "src/shaders/main/main.vs")
          .add(GL_FRAGMENT_SHADER, "src/shaders/main/main.fs")
          .add(GL_FRAGMENT_SHADER, "src/shaders/textures/scrollTexture.fs")
          .add(GL_FRAGMENT_SHADER, "src/shaders/main/phong.fs")
          .add(GL_FRAGMENT_SHADER, "src/shaders/main/lights.fs")
          .link();
}
    
void StreamRenderer::render() {
    shader.use();
    for (auto l : lights) { l->update(shader); }
    
    shader.setUniform("time", (float) glfwGetTime());
    
    shader.setUniform("view", camera.getViewMatrix());
    shader.setUniform("projection", camera.getProjectionMatrix());
    shader.setUniform("cameraPosition", camera.getPosition());
    
    shader.setUniform("model", waterfall.getModel().getModelMatrix());
    shader.setUniform("normalMatrix", waterfall.getModel().getNormalMatrix());
    
    waterfall.getModel().draw(shader);
    
    shader.setUniform("model", river.getModel().getModelMatrix());
    shader.setUniform("normalMatrix", river.getModel().getNormalMatrix());
    
    river.getModel().draw(shader);
}
