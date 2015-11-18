#ifndef BG_OBJECT_HPP
#define BG_OBJECT_HPP

#include <string>

#include "entities/Entity.hpp"
#include "models/Model.hpp"
#include "behaviours/collisions/BoundingBox.hpp"
#include "behaviours/collisions/Collidable.hpp"

class BgObject : public Entity, public Collidable {
public:
    BgObject(
        std::string path, const glm::vec3& position, const glm::vec3& scale,
        const BoundingBox& boundingBox
    );
    BgObject(const BgObject& bgObject, const BoundingBox& boundingBox);
    
    glm::vec3 getPosition() override;
    Model& getModel();
    
protected:
    Model model;
};

#endif // BG_OBJECT_HPP
