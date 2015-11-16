#include <vector>

#include "entities/skybox/Skybox.hpp"

Skybox::Skybox() :
    Entity("skybox"),
    model("resources/skybox/skybox.obj")
{
    std::vector<std::string> texturesPaths({
        "resources/skybox/right.jpg",
        "resources/skybox/left.jpg",
        "resources/skybox/top.jpg",
        "resources/skybox/bottom.jpg",
        "resources/skybox/back.jpg",
        "resources/skybox/front.jpg"
    });
    
    texture = std::make_unique<TextureCubeMap>(texturesPaths);
}

Model& Skybox::getModel() { return model; }
TextureCubeMap& Skybox::getTexture() { return *texture; }
