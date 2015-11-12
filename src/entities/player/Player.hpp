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
    glm::vec3 getPosition();
    
private:
    Model model;
    float speed;
    PlayerInputHandler inputHandler;
    
    void move();
};

#endif // PLAYER_HPP
