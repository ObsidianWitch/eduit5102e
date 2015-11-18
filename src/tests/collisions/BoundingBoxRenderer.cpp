#include "BoundingBoxRenderer.hpp"

#include "behaviours/collisions/BoundingBox.hpp"

BoundingBoxRenderer::BoundingBoxRenderer(
    Camera& camera, Player& player, std::vector<Collidable*>& collidables
) :
    camera(camera), player(player), collidables(collidables)
{
    shader.add(GL_VERTEX_SHADER, "src/tests/collisions/boundingBox.vs")
          .add(GL_GEOMETRY_SHADER, "src/tests/collisions/boundingBox.gs")
          .add(GL_FRAGMENT_SHADER, "src/tests/collisions/boundingBox.fs")
          .link();
    
    glGenVertexArrays(1, &vertexArray);
    glBindVertexArray(vertexArray);
    glBindVertexArray(0);
}

void BoundingBoxRenderer::render() {
    shader.use();
    shader.setUniform("view", camera.getViewMatrix());
    shader.setUniform("projection", camera.getProjectionMatrix());
    
    render(player.getBoundingBox());
    
    for (auto c : collidables) {
        render(c->getBoundingBox());
    }
}

void BoundingBoxRenderer::render(const BoundingBox& bb) {
    shader.setUniform("boundingBox.minPos", bb.minPos);
    shader.setUniform("boundingBox.maxPos", bb.maxPos);
    
    glBindVertexArray(vertexArray);
    glDrawArrays(GL_POINTS, 0, 1);
    glBindVertexArray(0);
}
