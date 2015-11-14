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
        bool silhouette = true
    );
    
    BgObject(
        std::string path, const glm::vec3& position, const glm::vec3& scale,
        const BoundingBox& boundingBox, bool silhouette = true
    );
    
    void update(Shader& shader) override;
    glm::vec3 getPosition() override;
    
private:
    Model model;
    bool silhouette;
};

#endif // BG_OBJECT_HPP
