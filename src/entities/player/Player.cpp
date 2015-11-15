#include <glm/gtc/constants.hpp>

#include "entities/player/Player.hpp"
#include "behaviours/collisions/BoundingBox.hpp"

Player::Player(const glm::vec3& position, float speed) :
    Entity("player"),
    Movable(speed),
    Collidable(BoundingBox(
        glm::vec3(-3.0f, 0.0f, -3.0f), // minPos
        glm::vec3(3.0f)                // maxPos
    )),
    model("resources/elf/elf.obj")
{
    model.translate(position);
    model.scale(glm::vec3(2.0f));
}

/**
 * Moves/Rotates the player in the directions specified by the eventHandler. The
 * movement vector's magnitude is clampled in order to move at the same speed in
 * all directions and avoid problems such as straferunning.
 */
void Player::move() {
    auto& states = eventHandler.getStates();
    
    // translate
    movementVec = glm::vec3(0.0f);
    if (states[FORWARD]) { movementVec.z += speed; }
    else if (states[BACKWARD]) { movementVec.z -= speed; }
    
    if (eventHandler.getStrafing()) {
        if (states[LEFT]) { movementVec.x += speed; }
        else if (states[RIGHT]) { movementVec.x -= speed; }
    }
    
    /// clamp movementVec's magnitude
    float ratio = glm::length(movementVec) / speed;
    if (ratio != 0) { movementVec /= ratio; }
    model.translate(movementVec);
    
    // rotate
    if (!eventHandler.getStrafing()) {
        if (states[LEFT]) {
            model.rotate(glm::radians(speed * 10));
        }
        else if (states[RIGHT]) {
            model.rotate(glm::radians(-speed * 10));
        }
    }
}

/**
 * Cancels the last translaton added by the movement vector.
 */
void Player::cancelMove() {
    model.translate(-movementVec);
}

/**
 * Updates the model matrix for the specified shader, and draws the model.
 * The shader in parameter should be bound before calling this method.
 */
void Player::update(Shader& shader) {
    shader.setUniform("model", model.getModelMatrix());
    shader.setUniform("normalMatrix", model.getNormalMatrix());
    shader.setUniform("setSilhouette", true);
    shader.setUniform("breathing", true);
    model.draw(shader);
}

PlayerEventHandler& Player::getEventHandler() { return eventHandler; }
glm::vec3 Player::getPosition() { return model.getPosition(); }
