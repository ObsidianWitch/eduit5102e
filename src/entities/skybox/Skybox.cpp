#include <vector>

#include "Skybox.hpp"

Skybox::Skybox() :
    Entity("skybox"),
    model("resources/skybox/skybox.obj")
{
    std::vector<std::string> texturesPaths;
    texturesPaths.push_back("resources/skybox/right.jpg");
    texturesPaths.push_back("resources/skybox/left.jpg");
    texturesPaths.push_back("resources/skybox/top.jpg");
    texturesPaths.push_back("resources/skybox/bottom.jpg");
    texturesPaths.push_back("resources/skybox/back.jpg");
    texturesPaths.push_back("resources/skybox/front.jpg");
    
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
