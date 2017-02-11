#include "models/Material.hpp"

Material::Material(const aiMaterial& material, std::string directory) {
    loadTexture(material, directory, aiTextureType_DIFFUSE, GL_TEXTURE0);
    normalMapIsSet = loadTexture(
        material, directory, aiTextureType_HEIGHT, GL_TEXTURE1
    );

    aiColor3D color;

    material.Get(AI_MATKEY_COLOR_AMBIENT, color);
    cAmbient = glm::vec4(color.r, color.g, color.b, 1.0f);

    material.Get(AI_MATKEY_COLOR_DIFFUSE, color);
    cDiffuse = glm::vec4(color.r, color.g, color.b, 1.0f);

    material.Get(AI_MATKEY_COLOR_SPECULAR, color);
    cSpecular = glm::vec4(color.r, color.g, color.b, 1.0f);

    material.Get(AI_MATKEY_SHININESS, shininess);
}

bool Material::loadTexture(
    const aiMaterial& material, std::string directory, aiTextureType type,
    GLenum unit
) {
    if (material.GetTextureCount(type) <= 0) { return false; }

    aiString textureFile;
    material.GetTexture(type, 0, &textureFile);

    int opacity;
    material.Get(AI_MATKEY_OPACITY, opacity);

    auto texturePath = directory + '/' + std::string(textureFile.C_Str());
    textures.push_back(Texture2D(
        texturePath, unit, !opacity
    ));

    return true;
}

void Material::update(Shader& shader) {
    shader.setUniform("material.diffuseMap", (GLuint) 0);
    shader.setUniform("material.normalMap", (GLuint) 1);
    shader.setUniform("material.normalMapIsSet", normalMapIsSet);

    shader.setUniform("material.cAmbient", cAmbient);
    shader.setUniform("material.cDiffuse", cDiffuse);
    shader.setUniform("material.cSpecular", cSpecular);
    shader.setUniform("material.shininess", shininess);
}

void Material::bindTextures() {
    for (auto& texture : textures) {
        texture.bind();
    }
}

void Material::unbindTextures() {
    for (auto& texture : textures) {
        texture.unbind();
    }
}
