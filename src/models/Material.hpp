#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <string>
#include <assimp/material.h>

#include "Texture.hpp"

class Material {
public:
    Material(const aiMaterial& material, std::string directory);
    
    void bindTextures();
    void unbindTextures();
    
private:
    std::vector<Texture> textures;
    
    void loadTexture(
        const aiMaterial& material, std::string directory, aiTextureType type
    );
};

#endif // MATERIAL_HPP
