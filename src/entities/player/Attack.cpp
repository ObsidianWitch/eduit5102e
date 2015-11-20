#include "entities/player/Attack.hpp"
#include "tools/LocalBasis.hpp"

Attack::Attack(Player& player) :
    Entity("attack"),
    player(player),
    magicCircle("resources/attack/circle1.obj"),
    magicTriangle("resources/attack/triangle.obj"),
    positionOffset(0.0f, 0.3f, 0.0f)
{
    updatePosition();
    magicTriangle.scale(glm::vec3(2.0f));
}

void Attack::update() {
    // transform 1st magic circle (ground)
    glm::mat4 transformationCircle(1.0f);
    transformationCircle = glm::rotate(
        transformationCircle, (float) glfwGetTime(), LocalBasis::y
    );
    transformationCircle = glm::scale(
        transformationCircle,
        glm::vec3((float) exp(sin(glfwGetTime())))
    );
    magicCircle.setTransformation(transformationCircle);
    
    // transform triangle inside the 1st magic circle
    glm::mat4 transformationTriangle(1.0f);
    transformationTriangle = glm::rotate(
        transformationTriangle, -0.5f * (float) glfwGetTime(), LocalBasis::y
    );
    magicTriangle.setTransformation(transformationTriangle);
    
    updatePosition();
}

void Attack::updatePosition() {
    magicCircle.setPosition(player.getPosition() + positionOffset);
    magicTriangle.setPosition(player.getPosition() + positionOffset);
}

Model& Attack::getMagicCircle() { return magicCircle; }
Model& Attack::getMagicTriangle() { return magicTriangle; }
