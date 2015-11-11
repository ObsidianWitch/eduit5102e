#include <iostream>
#include <vector>
#include <SOIL/SOIL.h>

#include "Skybox.hpp"

Skybox::Skybox() :
    Entity("skybox")
{
    GLfloat skyboxVertices[] = {
        -1.0f,  1.0f, -1.0f,
        -1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,

        -1.0f, -1.0f,  1.0f,
        -1.0f, -1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f, -1.0f,
        -1.0f,  1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f,

         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,

        -1.0f, -1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f, -1.0f,  1.0f,
        -1.0f, -1.0f,  1.0f,

        -1.0f,  1.0f, -1.0f,
         1.0f,  1.0f, -1.0f,
         1.0f,  1.0f,  1.0f,
         1.0f,  1.0f,  1.0f,
        -1.0f,  1.0f,  1.0f,
        -1.0f,  1.0f, -1.0f,

        -1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f,  1.0f,
         1.0f, -1.0f, -1.0f,
         1.0f, -1.0f, -1.0f,
        -1.0f, -1.0f,  1.0f,
         1.0f, -1.0f,  1.0f
    };

    glGenVertexArrays(1, &vao_);
    glBindVertexArray(vao_);
    
    GLuint vbo;
    glGenBuffers(1, &vbo);
    glBindBuffer(GL_ARRAY_BUFFER, vbo);
    glBufferData(
        GL_ARRAY_BUFFER, sizeof(skyboxVertices), &skyboxVertices, GL_STATIC_DRAW
    );
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(
        0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat), (GLvoid*) 0
    );

    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);

    std::vector<std::string> texturesPaths;
    texturesPaths.push_back("resources/skybox/right.jpg");
    texturesPaths.push_back("resources/skybox/left.jpg");
    texturesPaths.push_back("resources/skybox/top.jpg");
    texturesPaths.push_back("resources/skybox/bottom.jpg");
    texturesPaths.push_back("resources/skybox/back.jpg");
    texturesPaths.push_back("resources/skybox/front.jpg");
    texture.init(texturesPaths);
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
    
    texture.bind();
    
    glBindVertexArray(vao_);
    glDrawArrays(GL_TRIANGLES, 0, 36);
    glBindVertexArray(0);
    
    glDepthFunc(GL_LESS);
    texture.unbind();
}
