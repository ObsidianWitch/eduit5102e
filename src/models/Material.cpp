#include "Material.hpp"

Material::Material(const aiMaterial& material, std::string directory) {
    loadTexture(material, directory, aiTextureType_DIFFUSE);
}

void Material::loadTexture(
    const aiMaterial& material, std::string directory, aiTextureType type
) {
    if (material.GetTextureCount(type) > 0) {
        aiString textureFile;
        material.GetTexture(type, 0, &textureFile);
        
        std::string texturePath = directory + '/' + std::string(textureFile.C_Str());
        textures.push_back(Texture(
            texturePath, GL_TEXTURE0
        ));
    }
}

void Material::bindTextures() {
    for (Texture& texture : textures) {
        texture.bind();
    }
}

void Material::unbindTextures() {
    for (Texture& texture : textures) {
        texture.unbind();
    }
}
