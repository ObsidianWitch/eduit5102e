#ifndef ATTACK_HPP
#define ATTACK_HPP

#include <glm/gtc/matrix_transform.hpp>

#include "entities/Entity.hpp"
#include "entities/player/Player.hpp"

class Attack : public Entity {
public:
    Attack(Player& player);
    
    void update() override;
    
    Model& getMagicCircle();
    Model& getMagicTriangle();
    
private:
    Player& player;
    Model magicCircle;
    Model magicTriangle;
    // TODO Model magicCircle2;
    // TODO Model sphere;
    // TODO Model laser;
    glm::vec3 positionOffset;
    
    void updatePosition();
};

#endif // ATTACK_HPP
