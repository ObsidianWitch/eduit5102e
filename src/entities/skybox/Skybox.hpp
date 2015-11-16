#ifndef SKYBOX_HPP
#define SKYBOX_HPP

#include <memory>

#include "entities/Entity.hpp"
#include "models/Model.hpp"
#include "models/TextureCubeMap.hpp"

class Skybox : public Entity {
public:
    Skybox();
    
    Model& getModel();
    TextureCubeMap& getTextureBack();
    TextureCubeMap& getTextureFront();

private:
    Model model;
    std::unique_ptr<TextureCubeMap> textureBack;
    std::unique_ptr<TextureCubeMap> textureFront;
};

#endif // SKYBOX_HPP
