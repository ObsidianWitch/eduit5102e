#include "BgObject.hpp"

BgObject::BgObject(
    std::string path, const glm::vec3& position, const glm::vec3& scale,
    const BoundingBox& boundingBox
) :
    Entity("bgobject"),
    Collidable(boundingBox),
    model(path)
{
    model.setPosition(position)
         .scale(scale);
}

BgObject::BgObject(const BgObject& bgObject, const BoundingBox& boundingBox) :
    Entity("bgobject"),
    Collidable(boundingBox),
    model(bgObject.model)
{}

glm::vec3 BgObject::getPosition() { return model.getPosition(); }
Model& BgObject::getModel() { return model; }
