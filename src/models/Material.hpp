#ifndef MATERIAL_HPP
#define MATERIAL_HPP

#include <string>
#include <assimp/material.h>
#include <glm/glm.hpp>

#include "shaders/Shader.hpp"
#include "models/Texture2D.hpp"

class Material {
public:
    Material(const aiMaterial& material, std::string directory);
    
    void update(Shader& shader);
    
    void bindTextures();
    void unbindTextures();
    
private:
    std::vector<Texture2D> textures;
    glm::vec4 cAmbient;
    glm::vec4 cDiffuse;
    glm::vec4 cSpecular;
    float shininess;
    
    void loadTexture(
        const aiMaterial& material, std::string directory, aiTextureType type
    );
};

#endif // MATERIAL_HPP
