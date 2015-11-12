#include <glm/gtc/constants.hpp>

#include "entities/player/Player.hpp"

Player::Player(const glm::vec3& position, float speed) :
    Entity("player"),
    model("resources/nanosuit/nanosuit.obj")
{
    model.translate(position);
    
    this->speed = speed;
}

/**
 * Moves/Rotates the player in the directions specified by the inputHandler. The
 * movement vector's magnitude is clampled in order to move at the same speed in
 * all directions and avoid problems such as straferunning.
 */
void Player::move() {
    auto& states = inputHandler.getStates();
    
    // translate
    glm::vec3 movementVec = glm::vec3(0.0f);
    if (states[FORWARD]) { movementVec.z += speed; }
    else if (states[BACKWARD]) { movementVec.z -= speed; }
    
    if (inputHandler.getStrafing()) {
        if (states[LEFT]) { movementVec.x += speed; }
        else if (states[RIGHT]) { movementVec.x -= speed; }
    }
    
    /// clamp movementVec's magnitude
    float ratio = glm::length(movementVec) / speed;
    if (ratio != 0) { movementVec /= ratio; }
    model.translate(movementVec);
    
    // rotate
    if (!inputHandler.getStrafing()) {
        if (states[LEFT]) {
            model.rotate(glm::radians(speed * 10));
        }
        else if (states[RIGHT]) {
            model.rotate(glm::radians(-speed * 10));
        }
    }
}

/**
 * Updates the Player's position, updates the model matrix for the specified
 * shader, and draws his model.
 * The shader in parameter should be bound before calling this method.
 */
void Player::update(Shader& shader) {
    move();
    shader.setUniform("model", model.getModelMatrix());
    shader.setUniform("normalMatrix", model.getNormalMatrix());
    model.draw(shader);
}

PlayerInputHandler& Player::getInputHandler() { return inputHandler; }

glm::vec3 Player::getPosition() {
    return model.getPosition();
}
