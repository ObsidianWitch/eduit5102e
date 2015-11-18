#include <glm/gtc/constants.hpp>
#include <glm/gtc/matrix_transform.hpp>

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
    model.setPosition(position)
         .scale(glm::vec3(2.0f));
}

/**
 * Updates the transformation matrix to simulate breathing.
 */
void Player::update() {
    glm::vec3 breathingScaleVector = glm::vec3(1.0f);
    breathingScaleVector.y += 0.005f * exp(sin(glfwGetTime()));
    model.setTransformation(glm::scale(
        glm::mat4(), breathingScaleVector
    ));
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

PlayerEventHandler& Player::getEventHandler() { return eventHandler; }
glm::vec3 Player::getPosition() { return model.getPosition(); }
Model& Player::getModel() { return model; }
