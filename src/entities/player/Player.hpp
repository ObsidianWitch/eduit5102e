#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <glm/glm.hpp>

#include "models/Model.hpp"
#include "entities/Entity.hpp"
#include "entities/player/PlayerEventHandler.hpp"
#include "behaviours/movements/Movable.hpp"
#include "behaviours/collisions/Collidable.hpp"

class Player : public Entity, public Movable, public Collidable {
public:
    Player(const glm::vec3& position, float speed);
    
    void update() override;
    
    void move() override;
    void cancelMove() override;
    
    PlayerEventHandler& getEventHandler();
    glm::vec3 getPosition() override;
    Model& getModel();
    glm::mat4 getModelMatrix();
    glm::mat3 getNormalMatrix();
    
private:
    Model model;
    glm::mat4 transformation;
    PlayerEventHandler eventHandler;
};

#endif // PLAYER_HPP
