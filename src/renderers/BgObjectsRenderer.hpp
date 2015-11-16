#ifndef BG_OBJECTS_RENDERER_HPP
#define BG_OBJECTS_RENDERER_HPP

#include <memory>

#include "shaders/Shader.hpp"
#include "entities/Entity.hpp"
#include "entities/objects/BgObject.hpp"
#include "entities/camera/Camera.hpp"

class BgObjectsRenderer {
public:
    BgObjectsRenderer(
        std::vector<BgObject>& bgObjects, Camera& camera,
        std::vector<std::shared_ptr<Entity>>& lights
    );
    
    void render();
    
private:
    Shader shader;
    std::vector<BgObject>& bgObjects;
    Camera& camera;
};

#endif // BG_OBJECT_RENDERER_HPP
