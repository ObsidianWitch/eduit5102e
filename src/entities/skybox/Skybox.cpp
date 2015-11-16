#include <vector>

#include "entities/skybox/Skybox.hpp"

Skybox::Skybox() :
    Entity("skybox"),
    model("resources/skybox/skybox.obj")
{
    textureBack = std::make_unique<TextureCubeMap>(
        std::vector<std::string>({
            "resources/skybox/right.jpg",
            "resources/skybox/left.jpg",
            "resources/skybox/top.jpg",
            "resources/skybox/bottom.jpg",
            "resources/skybox/back.jpg",
            "resources/skybox/front.jpg"
        }),
        GL_TEXTURE0, false
    );
    
    textureFront = std::make_unique<TextureCubeMap>(
        std::vector<std::string>({
            "resources/skybox/fog_right.png",
            "resources/skybox/fog_left.png",
            "resources/skybox/fog_left.png",
            "resources/skybox/transparent.png",
            "resources/skybox/fog_back.png",
            "resources/skybox/fog_front.png"
        }),
        GL_TEXTURE1, true
    );
}

Model& Skybox::getModel() { return model; }
TextureCubeMap& Skybox::getTextureBack() { return *textureBack; }
TextureCubeMap& Skybox::getTextureFront() { return *textureFront; }
