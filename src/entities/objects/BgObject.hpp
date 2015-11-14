#ifndef BG_OBJECT_HPP
#define BG_OBJECT_HPP

#include <string>

#include "entities/Entity.hpp"
#include "models/Model.hpp"
#include "behaviours/collisions/BoundingBox.hpp"

class BgObject : public Entity {
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
    
    BoundingBox getBoundingBox();
    
private:
    Model model;
    BoundingBox boundingBox;
    bool silhouette;
};

#endif // BG_OBJECT_HPP
