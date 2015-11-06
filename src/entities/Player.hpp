#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "models/Model.hpp"
#include "PlayerInputHandler.hpp"

class Player {
public:
    Player(const glm::vec3& position, float speed);
    
    void update();
    
    glm::mat4 getModelMatrix();
    PlayerInputHandler& getInputHandler();
    
private:
    Model model;
    glm::vec3 position;
    float speed;
    PlayerInputHandler playerInputHandler;
    
    void move(bool forward, bool backward, bool left, bool right, bool strafing);
    void updateMove();
};

#endif // PLAYER_HPP
