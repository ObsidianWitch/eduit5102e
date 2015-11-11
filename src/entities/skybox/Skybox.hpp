#ifndef SKYBOX_HPP
#define SKYBOX_HPP

#include <memory>

#include "entities/Entity.hpp"
#include "models/Model.hpp"
#include "models/TextureCubeMap.hpp"

class Skybox : public Entity {
public:
    Skybox();

    void update(Shader& shader);

private:
    Model model;
    std::unique_ptr<TextureCubeMap> texture;
};

#endif // SKYBOX_HPP
