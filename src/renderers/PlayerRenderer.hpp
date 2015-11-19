#ifndef PLAYER_RENDERER_HPP
#define PLAYER_RENDERER_HPP

#include <memory>

#include "shaders/Shader.hpp"
#include "entities/Entity.hpp"
#include "entities/player/Player.hpp"
#include "entities/camera/Camera.hpp"

class PlayerRenderer {
public:
    PlayerRenderer(
        Player& player, Camera& camera,
        std::vector<std::shared_ptr<Entity>>& lights
    );
    
    void render();
    
private:
    Shader shader;
    Player& player;
    Camera& camera;
    std::vector<std::shared_ptr<Entity>>& lights;
};

#endif // PLAYER_RENDERER_HPP
