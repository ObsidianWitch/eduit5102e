#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "models/Model.hpp"
#include "entities/Entity.hpp"
#include "entities/player/PlayerInputHandler.hpp"

class Player : public Entity {
public:
    Player(const glm::vec3& position, float speed);
    
    void update(Shader& shader) override;
    
    PlayerInputHandler& getInputHandler();
    
private:
    Model model;
    float speed;
    PlayerInputHandler playerInputHandler;
    
    void move(bool forward, bool backward, bool left, bool right, bool strafing);
    void updateMove();
};

#endif // PLAYER_HPP
