#include "BgObject.hpp"

BgObject::BgObject(
    std::string path, const glm::vec3& position, const glm::vec3& scale,
    bool silhouette
) :
    Entity("skybox"),
    model(path)
{
    model.translate(position);
    model.scale(scale);
    this->silhouette = silhouette;
}

void BgObject::update(Shader& shader) {
    shader.setUniform("model", model.getModelMatrix());
    shader.setUniform("normalMatrix", model.getNormalMatrix());
    shader.setUniform("setSilhouette", silhouette);
    model.draw(shader);
}
