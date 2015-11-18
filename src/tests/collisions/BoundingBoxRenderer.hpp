#ifndef BOUNDING_BOX_RENDERER_HPP
#define BOUNDING_BOX_RENDERER_HPP

#include "shaders/Shader.hpp"
#include "behaviours/collisions/Collidable.hpp"
#include "entities/player/Player.hpp"
#include "entities/camera/Camera.hpp"

class BoundingBoxRenderer {
public:
    BoundingBoxRenderer(
        Camera& camera, Player& player, std::vector<Collidable*>& collidables
    );
    
    void render();
    void render(const BoundingBox& bb);
    
private:
    Shader shader;
    GLuint vertexArray;
    Camera& camera;
    Player& player;
    std::vector<Collidable*>& collidables;
};

#endif // BOUNDING_BOX_RENDERER_HPP
