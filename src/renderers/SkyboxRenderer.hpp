#ifndef SKYBOX_RENDERER_HPP
#define SKYBOX_RENDERER_HPP

#include "shaders/Shader.hpp"
#include "entities/skybox/Skybox.hpp"
#include "entities/camera/Camera.hpp"

class SkyboxRenderer {
public:
    SkyboxRenderer(Skybox& skybox, Camera& camera);
    
    void render();
    
private:
    Shader shader;
    Skybox& skybox;
    Camera& camera;
};

#endif // SKYBOX_RENDERER_HPP
