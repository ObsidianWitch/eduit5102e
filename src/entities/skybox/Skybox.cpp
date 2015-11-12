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

/**
 * Displays the skybox.
 * @note The depth function is changed from LESS to LEQUAL so that the skybox
 * passes the depth test. The depth buffer will be filled with the maximum
 * value (1.0) for the skybox.
 */
void Skybox::update(Shader& shader) {
    shader.setUniform("skybox", (GLuint) 0);
    
    glDepthFunc(GL_LEQUAL);
    
    texture->bind();
    
    model.draw(shader);
    
    glDepthFunc(GL_LESS);
    texture->unbind();
}
