#include <iostream>
#include <vector>
#include <SOIL/SOIL.h>

#include "models/TextureCubeMap.hpp"

TextureCubeMap::TextureCubeMap(const std::vector<std::string>& texturesPaths) {
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_CUBE_MAP, id);

    load(texturesPaths);
    setParameters();
    
    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
}

void TextureCubeMap::load(const std::vector<std::string>& texturesPaths) {
    for (unsigned int i = 0 ; i < texturesPaths.size() ; i++) {
        int width, height;
        unsigned char* image = SOIL_load_image(
            texturesPaths[i].c_str(), //path
            &width, &height,          // width & height
            nullptr,                  // channels
            SOIL_LOAD_RGB             // force channels
        );
        if (image == nullptr) {
            std::cerr << "Texture " << texturesPaths[i]
                      << " could not be loaded." << std::endl
                      << SOIL_last_result() << std::endl;
            exit(EXIT_FAILURE);
        }

        glTexImage2D(
            GL_TEXTURE_CUBE_MAP_POSITIVE_X + i, // target
            0,                                  // mipmap level (base image)
            GL_RGB,                             // texture internal format
            width, height,                      // width & height
            0,                                  // border (legacy)
            GL_RGB,                             // texel data format
            GL_UNSIGNED_BYTE,                   // texel data type
            image                               // image data
        );
        SOIL_free_image_data(image);
    }
}

void TextureCubeMap::setParameters() {
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
    glTexParameteri(GL_TEXTURE_CUBE_MAP, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
}

void TextureCubeMap::bind() {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, id);
}

void TextureCubeMap::unbind() {
    glActiveTexture(GL_TEXTURE0);
    glBindTexture(GL_TEXTURE_CUBE_MAP, 0);
}
