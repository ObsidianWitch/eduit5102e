#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "models/Model.hpp"

class Player {
public:
    Player(const glm::vec3& position, float speed);
    
    void draw();
    glm::mat4 getModelMatrix();
    
private:
    Model model;
    glm::vec3 position;
    float speed;
};

#endif // PLAYER_HPP
