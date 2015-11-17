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
        const BoundingBox& boundingBox, bool silhouette
    );
    BgObject(const BgObject& bgObject, const glm::vec3& position);
    
    glm::vec3 getPosition() override;
    Model& getModel();
    bool hasSilhouette();
    
private:
    Model model;
    bool silhouette;
};

#endif // BG_OBJECT_HPP
