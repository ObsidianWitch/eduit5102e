#include "Material.hpp"

Material::Material(const aiMaterial& material, std::string directory) {
    loadTexture(material, directory, aiTextureType_DIFFUSE);
    
    cAmbient = glm::vec3(0.4f); // FIXME
    cDiffuse = glm::vec3(0.64f); // FIXME
    cSpecular = glm::vec3(0.5f); // FIXME
    shininess = 50.0f; // FIXME
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

void Material::update(Shader& shader) {
    shader.setUniform("material.diffuse", (GLuint) 0);
    shader.setUniform("material.cAmbient", cAmbient);
    shader.setUniform("material.cDiffuse", cDiffuse);
    shader.setUniform("material.cSpecular", cSpecular);
    shader.setUniform("material.shininess", shininess);
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
