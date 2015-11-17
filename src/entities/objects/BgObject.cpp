#include "BgObject.hpp"

BgObject::BgObject(
    std::string path, const glm::vec3& position, const glm::vec3& scale,
    const BoundingBox& boundingBox, bool silhouette
) :
    Entity("bgobject"),
    Collidable(boundingBox),
    model(path)
{
    model.setPosition(position);
    model.scale(scale);
    this->silhouette = silhouette;
}

BgObject::BgObject(const BgObject& bgObject, const glm::vec3& position) :
    BgObject(bgObject)
{
    model.setPosition(position);
}

glm::vec3 BgObject::getPosition() { return model.getPosition(); }
Model& BgObject::getModel() { return model; }
bool BgObject::hasSilhouette() { return silhouette; }
