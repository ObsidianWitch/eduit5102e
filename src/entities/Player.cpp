#include "Player.hpp"

Player::Player(const glm::vec3& position, float speed) :
    model("resources/nanosuit/nanosuit.obj")
{
    // approximately centers the model
    model.translate(glm::vec3(0.0f, -10.0f, 0.0f));
    
    this->position = position;
    model.translate(position);
    
    this->speed = speed;
}

void Player::draw() { model.draw(); }
glm::mat4 Player::getModelMatrix() { return model.getModelMatrix(); }
