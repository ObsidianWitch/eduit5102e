#include "PlayerRenderer.hpp"

PlayerRenderer::PlayerRenderer(
    Player& player, Camera& camera, std::vector<std::shared_ptr<Entity>>& lights
) :
    player(player), camera(camera)
{
    shader.add(GL_VERTEX_SHADER, "src/shaders/main/main.vs")
          .add(GL_FRAGMENT_SHADER, "src/shaders/main/main.fs")
          .add(GL_FRAGMENT_SHADER, "src/shaders/main/toon.fs")
          .add(GL_FRAGMENT_SHADER, "src/shaders/main/lights.fs")
          .link();
    
    shader.use();
    for (auto l : lights) { l->update(shader); }
}

void PlayerRenderer::render() {
    shader.use();
    shader.setUniform("time", (float) glfwGetTime());
    
    shader.setUniform("view", camera.getViewMatrix());
    shader.setUniform("projection", camera.getProjectionMatrix());
    shader.setUniform("cameraPosition", camera.getPosition());
    
    shader.setUniform("model", player.getModel().getModelMatrix());
    shader.setUniform("normalMatrix", player.getModel().getNormalMatrix());
    shader.setUniform("setSilhouette", true);
    shader.setUniform("breathing", true);
    
    player.getModel().draw(shader);
}
