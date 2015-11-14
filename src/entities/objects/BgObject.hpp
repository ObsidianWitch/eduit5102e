#ifndef BG_OBJECT_HPP
#define BG_OBJECT_HPP

#include <string>

#include "entities/Entity.hpp"
#include "models/Model.hpp"

class BgObject : public Entity {
public:
    BgObject(
        std::string path, const glm::vec3& position, const glm::vec3& scale,
        bool silhouette = true
    );
    
    void update(Shader& shader) override;
    
private:
    Model model;
    bool silhouette;
};

#endif // BG_OBJECT_HPP
