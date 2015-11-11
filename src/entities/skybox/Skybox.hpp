#ifndef SKYBOX_HPP
#define SKYBOX_HPP

#include "entities/Entity.hpp"
#include "models/TextureCubeMap.hpp"

class Skybox : public Entity {
public:
    Skybox();

    void update(Shader& shader);

private:
    GLuint vao_;
    TextureCubeMap texture;
};

#endif // SKYBOX_HPP
