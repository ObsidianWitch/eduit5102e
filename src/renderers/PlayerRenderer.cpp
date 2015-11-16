#include <glm/gtc/matrix_transform.hpp>

#include "PlayerRenderer.hpp"

PlayerRenderer::PlayerRenderer(
    Player& player, Camera& camera, std::vector<std::shared_ptr<Entity>>& lights
) :
    player(player), camera(camera)
{
    shader.add(GL_VERTEX_SHADER, "src/shaders/main/main.vs")
          .add(GL_FRAGMENT_SHADER, "src/shaders/main/main.fs")
          .add(GL_FRAGMENT_SHADER, "src/shaders/main/texture.fs")
          .add(GL_FRAGMENT_SHADER, "src/shaders/main/toon.fs")
          .add(GL_FRAGMENT_SHADER, "src/shaders/main/lights.fs")
          .link();
    
    shader.use();
    for (auto l : lights) { l->update(shader); }
}

void PlayerRenderer::render() {
    // breathe
    glm::vec3 breathingScaleVector = glm::vec3(1.0f);
    breathingScaleVector.y += 0.005f * exp(sin(glfwGetTime()));
    glm::mat4 modelMatrix = glm::scale(
        player.getModel().getModelMatrix(), breathingScaleVector
    );
    
    shader.use();
    shader.setUniform("view", camera.getViewMatrix());
    shader.setUniform("projection", camera.getProjectionMatrix());
    shader.setUniform("cameraPosition", camera.getPosition());
    
    shader.setUniform("model", modelMatrix);
    shader.setUniform("normalMatrix", player.getModel().getNormalMatrix());
    shader.setUniform("hasSilhouette", true);
    
    player.getModel().draw(shader);
}
