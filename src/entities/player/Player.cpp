#include <glm/gtc/constants.hpp>

#include "entities/player/Player.hpp"

Player::Player(const glm::vec3& position, float speed) :
    Entity("player", position),
    model("resources/nanosuit/nanosuit.obj")
{
    // approximately centers the model
    model.translate(glm::vec3(0.0f, -10.0f, 0.0f));
    
    this->position = position;
    model.translate(position);
    
    this->speed = speed;
}

void Player::updateMove() {
    auto& keyStates = playerInputHandler.getKeyStates();
    
    move(
        keyStates[GLFW_KEY_W], // forward
        keyStates[GLFW_KEY_S], // backward
        keyStates[GLFW_KEY_A], // left
        keyStates[GLFW_KEY_D], // right
        playerInputHandler.getStrafing()
    );
}

/**
 * Moves the player in the directions specified in parameter. The Player's speed
 * is used to determine the movement delta. If the Player moves at the same time
 * along the x and z axes, then the movement direction is a diagonal. The axes
 * are handled separately, meaning if the player moves in a diagonal, he would
 * move sqrt(2) units in this direction if nothing was done. We divide the
 * delta by sqrt(2) in this case to avoid straferunning (moving quicker in the
 * diagonal directions).
 */
void Player::move(
    bool forward, bool backward, bool left, bool right, bool strafing
) {
    bool diagonal = (forward || backward) && (left || right);
    
    float delta = speed;
    if (diagonal) { delta /= glm::root_two<float>(); }
    
    if (forward) {
        model.translate(glm::vec3(0.0f, 0.0f, delta));
    }
    else if (backward) {
        model.translate(glm::vec3(0.0f, 0.0f, -delta));
    }
    
    if (strafing) {
        if (left) {
            model.translate(glm::vec3(delta, 0.0f, 0.0f));
        }
        else if (right) {
            model.translate(glm::vec3(-delta, 0.0f, 0.0f));
        }
    }
    else {
        if (left) {
            model.rotate(glm::radians(speed * 10));
        }
        else if (right) {
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
    updateMove();
    shader.setUniform("model", model.getModelMatrix());
    model.draw(shader);
}

PlayerInputHandler& Player::getInputHandler() { return playerInputHandler; }
