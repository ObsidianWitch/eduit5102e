#include "BgObject.hpp"

BgObject::BgObject(
    std::string path, const glm::vec3& position, const glm::vec3& scale
) :
    Entity("skybox"),
    model(path)
{
    model.translate(position);
    model.scale(scale);
}

void BgObject::update(Shader& shader) {
    shader.setUniform("model", model.getModelMatrix());
    shader.setUniform("normalMatrix", model.getNormalMatrix());
    model.draw(shader);
}
