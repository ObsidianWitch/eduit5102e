#include "entities/player/Attack.hpp"
#include "tools/LocalBasis.hpp"

Attack::Attack(Player& player) :
    Entity("attack"),
    player(player),
    magicCircle1("resources/attack/circle1.obj"),
    magicCircle2(magicCircle1),
    magicTriangle("resources/attack/triangle.obj"),
    positionOffsetGround(0.0f, 0.3f, 0.0f),
    positionOffsetAir(0.0f, 8.0f, 5.0f)
{
    updatePosition();
    magicTriangle.scale(glm::vec3(2.0f));
    magicCircle2.scale(glm::vec3(0.5f))
                .rotate(glm::radians(90.0f), LocalBasis::z)
                .rotate(glm::radians(90.0f), LocalBasis::x);
}

void Attack::update() {
    // transform magic circles
    glm::mat4 transformationCircle(1.0f);
    transformationCircle = glm::rotate(
        transformationCircle, (float) glfwGetTime(), LocalBasis::y
    );
    magicCircle2.setTransformation(transformationCircle);
    
    transformationCircle = glm::scale(
        transformationCircle,
        glm::vec3((float) exp(sin(glfwGetTime())))
    );
    magicCircle1.setTransformation(transformationCircle);
    
    // transform magic triangle
    glm::mat4 transformationTriangle(1.0f);
    transformationTriangle = glm::rotate(
        transformationTriangle, -0.5f * (float) glfwGetTime(), LocalBasis::y
    );
    magicTriangle.setTransformation(transformationTriangle);
    
    updatePosition();
}

void Attack::updatePosition() {
    magicCircle1.setPosition(player.getPosition() + positionOffsetGround);
    magicCircle2.setPosition(player.getPosition() + positionOffsetAir);
    magicTriangle.setPosition(player.getPosition() + positionOffsetGround);
}

Model& Attack::getMagicCircle1() { return magicCircle1; }
Model& Attack::getMagicCircle2() { return magicCircle2; }
Model& Attack::getMagicTriangle() { return magicTriangle; }
