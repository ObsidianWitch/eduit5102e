#include "AttackRenderer.hpp"

AttackRenderer::AttackRenderer(
    Attack& attack, Camera& camera,
    std::vector<std::shared_ptr<Entity>>& lights
) :
    attack(attack), camera(camera), lights(lights)
{
    shader.add(GL_VERTEX_SHADER, "src/shaders/main/main.vs")
          .add(GL_FRAGMENT_SHADER, "src/shaders/main/main.fs")
          .add(GL_FRAGMENT_SHADER, "src/shaders/textures/texture.fs")
          .add(GL_FRAGMENT_SHADER, "src/shaders/main/phong.fs")
          .add(GL_FRAGMENT_SHADER, "src/shaders/main/lights.fs")
          .link();
}
    
void AttackRenderer::render() {
    shader.use();
    for (auto l : lights) { l->update(shader); }
    
    shader.setUniform("view", camera.getViewMatrix());
    shader.setUniform("projection", camera.getProjectionMatrix());
    shader.setUniform("cameraPosition", camera.getPosition());
    
    // 1st magic circle
    shader.setUniform(
        "model",
        attack.getMagicCircle().getModelMatrix()
    );
    shader.setUniform(
        "normalMatrix", attack.getMagicCircle().getNormalMatrix()
    );
    attack.getMagicCircle().draw(shader);
    
    // triangle
    shader.setUniform(
        "model",
        attack.getMagicTriangle().getModelMatrix()
    );
    shader.setUniform(
        "normalMatrix", attack.getMagicTriangle().getNormalMatrix()
    );
    attack.getMagicTriangle().draw(shader);
}
