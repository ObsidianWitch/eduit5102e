#ifndef BOUNDING_BOX_HPP
#define BOUNDING_BOX_HPP

#include <glm/glm.hpp>

class BoundingBox {
public:
    BoundingBox(const glm::vec3& minVec, const glm::vec3& maxVec);
    
    BoundingBox operator+(const glm::vec3& vec);
    
    glm::vec3 minVec;
    glm::vec3 maxVec;
};

#endif // BOUNDING_BOX_HPP
