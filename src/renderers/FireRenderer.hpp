#ifndef FIRE_RENDERER_HPP
#define FIRE_RENDERER_HPP

#include "shaders/Shader.hpp"
#include "entities/objects/BgObject.hpp"
#include "entities/camera/Camera.hpp"

class FireRenderer {
public:
    FireRenderer(BgObject& fire, Camera& camera);
    
    void render();
    
private:
    Shader shader;
    BgObject& fire;
    Camera& camera;
};

#endif // BG_OBJECT_RENDERER_HPP
