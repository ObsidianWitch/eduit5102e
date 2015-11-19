#include "BgObjectsRenderer.hpp"

BgObjectsRenderer::BgObjectsRenderer(
    std::vector<BgObject*>& bgObjects, Camera& camera,
    std::vector<std::shared_ptr<Entity>>& lights
) :
    bgObjects(bgObjects), camera(camera), lights(lights)
{
    shader.add(GL_VERTEX_SHADER, "src/shaders/main/main.vs")
          .add(GL_FRAGMENT_SHADER, "src/shaders/main/main.fs")
          .add(GL_FRAGMENT_SHADER, "src/shaders/textures/texture.fs")
          .add(GL_FRAGMENT_SHADER, "src/shaders/main/phong.fs")
          .add(GL_FRAGMENT_SHADER, "src/shaders/main/lights.fs")
          .link();
}
    
void BgObjectsRenderer::render() {
    shader.use();
    for (auto l : lights) { l->update(shader); }
    
    shader.setUniform("view", camera.getViewMatrix());
    shader.setUniform("projection", camera.getProjectionMatrix());
    shader.setUniform("cameraPosition", camera.getPosition());
    
    for (auto o : bgObjects) {
        shader.setUniform("model", o->getModel().getModelMatrix());
        shader.setUniform("normalMatrix", o->getModel().getNormalMatrix());
        
        o->getModel().draw(shader);
    }
}
