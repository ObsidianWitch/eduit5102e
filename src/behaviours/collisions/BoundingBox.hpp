#ifndef BOUNDING_BOX_HPP
#define BOUNDING_BOX_HPP

#include <glm/glm.hpp>

class BoundingBox {
public:
    BoundingBox(const glm::vec3& minPos, const glm::vec3& maxPos);
    
    BoundingBox operator+(const glm::vec3& vec);
    
    glm::vec3 minPos;
    glm::vec3 maxPos;
};

#endif // BOUNDING_BOX_HPP
