#ifndef COLLISION_HPP
#define COLLISION_HPP

#include "collisions/BoundingBox.hpp"

class Collision {
public:
    static bool check(const BoundingBox& box1, const BoundingBox& box2);
};

#endif // COLLISION_HPP
