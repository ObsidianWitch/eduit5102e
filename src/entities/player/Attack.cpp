#include "entities/player/Attack.hpp"
#include "tools/LocalBasis.hpp"

Attack::Attack(Player& player) :
    Entity("attack"),
    player(player),
    magicCircle("resources/attack/circle1.obj"),
    positionOffset(0.0f, 0.3f, 0.0f)
{
    updatePosition();
}

void Attack::update() {
    glm::mat4 transformation(1.0f);
    transformation = glm::rotate(transformation, (float) glfwGetTime(), LocalBasis::y);
    transformation = glm::scale(
        transformation,
        glm::vec3((float) exp(sin(glfwGetTime())))
    );
    
    magicCircle.setTransformation(transformation);
    updatePosition();
}

void Attack::updatePosition() {
    magicCircle.setPosition(player.getPosition() + positionOffset);
}

Model& Attack::getMagicCircle() { return magicCircle; }
