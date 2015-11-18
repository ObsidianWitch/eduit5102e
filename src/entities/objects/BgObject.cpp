#include "BgObject.hpp"

BgObject::BgObject(
    std::string path, const glm::vec3& position, const glm::vec3& scale,
    const BoundingBox& boundingBox, bool silhouette
) :
    Entity("bgobject"),
    Collidable(boundingBox),
    model(path)
{
    model.setPosition(position)
         .scale(scale);
    this->silhouette = silhouette;
}

BgObject::BgObject(const BgObject& bgObject, const BoundingBox& boundingBox) :
    Entity("bgobject"),
    Collidable(boundingBox),
    model(bgObject.model),
    silhouette(bgObject.silhouette)
{}

glm::vec3 BgObject::getPosition() { return model.getPosition(); }
Model& BgObject::getModel() { return model; }
bool BgObject::hasSilhouette() { return silhouette; }
