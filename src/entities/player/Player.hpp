#ifndef PLAYER_HPP
#define PLAYER_HPP

#include "models/Model.hpp"
#include "entities/Entity.hpp"
#include "entities/player/PlayerEventHandler.hpp"
#include "behaviours/movements/Movable.hpp"
#include "behaviours/collisions/Collidable.hpp"

class Player : public Entity, public Movable, public Collidable {
public:
    Player(const glm::vec3& position, float speed);
    
    void move() override;
    void cancelMove() override;
    void update(Shader& shader) override;
    
    PlayerEventHandler& getEventHandler();
    glm::vec3 getPosition() override;
    
private:
    Model model;
    PlayerEventHandler eventHandler;
};

#endif // PLAYER_HPP
