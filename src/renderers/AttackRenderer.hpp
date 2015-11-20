#ifndef ATTACK_RENDERER_HPP
#define ATTACK_RENDERER_HPP

#include <memory>

#include "shaders/Shader.hpp"
#include "entities/player/Attack.hpp"
#include "entities/camera/Camera.hpp"

class AttackRenderer {
public:
    AttackRenderer(
        Attack& attack, Camera& camera,
        std::vector<std::shared_ptr<Entity>>& lights
    );
    
    void render();
    void render(Model& model);
    
private:
    Shader shader;
    Attack& attack;
    Camera& camera;
    std::vector<std::shared_ptr<Entity>>& lights;
};

#endif // ATTACK_RENDERER_HPP
