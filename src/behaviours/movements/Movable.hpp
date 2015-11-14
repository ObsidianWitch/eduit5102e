#ifndef MOVABLE_HPP
#define MOVABLE_HPP

#include <glm/glm.hpp>

class Movable {
public:
    Movable(float speed);
    virtual ~Movable();
    
    virtual void move() = 0;
    virtual void cancelMove() = 0;
    
protected:
    glm::vec3 movementVec;
    float speed;
};

#endif // MOVABLE_HPP
