#ifndef LOCAL_BASIS_HPP
#define LOCAL_BASIS_HPP

#include <glm/glm.hpp>

/**
 * LocalBasis represents the coordinate space local to any object by using a
 * right-handed system.
 */
class LocalBasis {
public:
    static const glm::vec3 x;
    static const glm::vec3 y;
    static const glm::vec3 z;
};

#endif // LOCAL_BASIS_HPP
