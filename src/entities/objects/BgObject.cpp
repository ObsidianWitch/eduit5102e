#include "BgObject.hpp"

BgObject::BgObject(
    std::string path, const glm::vec3& position, const glm::vec3& scale,
    bool silhouette
) :
    Entity("bgobject"),
    model(path),
    boundingBox(glm::vec3(0.0f), glm::vec3(0.0f))
{
    model.translate(position);
    model.scale(scale);
    this->silhouette = silhouette;
}

BgObject::BgObject(
    std::string path, const glm::vec3& position, const glm::vec3& scale,
    const BoundingBox& boundingBox, bool silhouette
) : BgObject(path, position, scale, silhouette)
{
    this->boundingBox = boundingBox;
}

void BgObject::update(Shader& shader) {
    shader.setUniform("model", model.getModelMatrix());
    shader.setUniform("normalMatrix", model.getNormalMatrix());
    shader.setUniform("setSilhouette", silhouette);
    model.draw(shader);
}

BoundingBox BgObject::getBoundingBox() {
    return boundingBox + model.getPosition();
}
