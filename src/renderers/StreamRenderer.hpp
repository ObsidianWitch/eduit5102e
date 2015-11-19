#ifndef STREAM_RENDERER_HPP
#define STREAM_RENDERER_HPP

#include <memory>

#include "shaders/Shader.hpp"
#include "entities/Entity.hpp"
#include "entities/objects/BgObject.hpp"
#include "entities/camera/Camera.hpp"

class StreamRenderer {
public:
    StreamRenderer(
        BgObject& river, BgObject& waterfall, Camera& camera,
        std::vector<std::shared_ptr<Entity>>& lights
    );
    
    void render();
    
private:
    Shader shader;
    BgObject& river;
    BgObject& waterfall;
    Camera& camera;
};

#endif // STREAM_RENDERER_HPP
