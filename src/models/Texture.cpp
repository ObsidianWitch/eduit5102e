#include <iostream>
#include <SOIL/SOIL.h>

#include "Texture.hpp"

Texture::Texture(std::string path, GLenum unit) {
    this->path = path;
    this->unit = unit;
    
    load(path);
}

/**
 * Loads an image as a 2D Texture.
 */
void Texture::load(std::string path) {
    int width, height;
    unsigned char* image = SOIL_load_image(
        path.c_str(),    // path
        &width, &height, // width & height
        nullptr,         // channels
        SOIL_LOAD_RGB    // force channels
    );
    if (image == nullptr) {
        std::cerr << "Texture " << path << " could not be loaded." << std::endl;
        exit(EXIT_FAILURE);
    }
    
    glGenTextures(1, &id);
    glBindTexture(GL_TEXTURE_2D, id);
    glTexImage2D(
        GL_TEXTURE_2D,    // target
        0,                // manual mipmap level (0 base image level)
        GL_RGB,           // texture internal format (channels)
        width, height,    // width & height
        0,                // border (legacy)
        GL_RGB,           // texel data format
        GL_UNSIGNED_BYTE, // texel data type
        image             // image data
    );
    glGenerateMipmap(GL_TEXTURE_2D);
    
    setParameters();
    
    glBindTexture(GL_TEXTURE_2D, 0);
    SOIL_free_image_data(image);
}

/**
 * Sets parameters for the currently bound texture.
 * Texture wrapping: repeat Texture.
 * Minifying filter: nearest mipmap, and nearest texel (nearest neighbour
 * filtering).
 * Magnifying: linear filtering, interpolates values from the texture's
 * neighbouring texels.
 */
void Texture::setParameters() {
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
    
    glTexParameteri(
        GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR
    );
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
}

void Texture::bind() {
    glActiveTexture(unit);
    glBindTexture(GL_TEXTURE_2D, id);
}

void Texture::unbind() {
    glActiveTexture(unit);
    glBindTexture(GL_TEXTURE_2D, 0);
}

std::string Texture::getPath() { return path; }
