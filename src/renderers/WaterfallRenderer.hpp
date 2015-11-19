#ifndef WATERFALL_RENDERER_HPP
#define WATERFALL_RENDERER_HPP

#include <memory>

#include "shaders/Shader.hpp"
#include "entities/Entity.hpp"
#include "entities/objects/BgObject.hpp"
#include "entities/camera/Camera.hpp"

class WaterfallRenderer {
public:
    WaterfallRenderer(
        BgObject& waterfall, Camera& camera,
        std::vector<std::shared_ptr<Entity>>& lights
    );
    
    void render();
    
private:
    Shader shader;
    BgObject& waterfall;
    Camera& camera;
};

#endif // WATERFALL_RENDERER_HPP
