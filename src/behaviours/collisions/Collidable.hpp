#ifndef COLLIDABLE_HPP
#define COLLIDABLE_HPP

#include <glm/glm.hpp>

#include "behaviours/collisions/Collidable.hpp"
#include "behaviours/collisions/BoundingBox.hpp"

class Collidable {
public:
    Collidable(const BoundingBox& boundingBox);
    
    bool collide(Collidable& b);
    
    virtual glm::vec3 getPosition() = 0;
    BoundingBox getBoundingBox();
    
protected:
    BoundingBox boundingBox;
};

#endif // COLLIDABLE_HPP
