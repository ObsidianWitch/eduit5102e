#ifndef ATTACK_HPP
#define ATTACK_HPP

#include <glm/gtc/matrix_transform.hpp>

#include "entities/Entity.hpp"
#include "entities/player/Player.hpp"
#include "entities/player/AttackEventHandler.hpp"

class Attack : public Entity {
public:
    Attack(Player& player);

    void update() override;

    glm::mat4 getModelMatrix(Model& model);
    Model& getMagicCircle1();
    Model& getMagicCircle2();
    Model& getMagicCircle3();
    Model& getMagicTriangle();
    Model& getOrb();
    Model& getLaser();

    bool isLoading();
    bool isAttacking();

private:
    Player& player;
    Model magicCircle1;
    Model magicCircle2;
    Model magicCircle3;
    Model magicTriangle;
    Model orb;
    Model laser;

    glm::vec3 positionOffsetGround;
    glm::vec3 positionOffsetAir;

    AttackEventHandler eventHandler;
};

#endif // ATTACK_HPP
