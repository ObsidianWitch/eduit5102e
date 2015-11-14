#include "BgObject.hpp"

BgObject::BgObject(
    std::string path, const glm::vec3& position, const glm::vec3& scale,
    const BoundingBox& boundingBox, bool silhouette
) :
    Entity("bgobject"),
    Collidable(boundingBox),
    model(path)
{
    model.translate(position);
    model.scale(scale);
    this->silhouette = silhouette;
}

BgObject::BgObject(
    std::string path, const glm::vec3& position, const glm::vec3& scale,
    bool silhouette
) :
    BgObject(
        path, position, scale,
        BoundingBox(glm::vec3(0.0f), glm::vec3(0.0f)),
        silhouette
    )
{}

void BgObject::update(Shader& shader) {
    shader.setUniform("model", model.getModelMatrix());
    shader.setUniform("normalMatrix", model.getNormalMatrix());
    shader.setUniform("setSilhouette", silhouette);
    model.draw(shader);
}

glm::vec3 BgObject::getPosition() { return model.getPosition(); }
