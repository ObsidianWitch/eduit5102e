#version 330 core

struct Material {
    sampler2D diffuseMap;
    sampler2D normalMap;
    bool normalMapIsSet;
    
    vec4 cAmbient;
    vec4 cDiffuse;
    vec4 cSpecular;
    float shininess;
};

in vec2 fsTextureCoords;

out vec4 color;

uniform Material material;
uniform float time;

vec4 diffuseTexColor() {
    vec2 rotatingTexCoords = fsTextureCoords;
    rotatingTexCoords.y += 0.5f * time;
    
    vec4 diffuseTexColor = texture(material.diffuseMap, rotatingTexCoords) * 2;
    if (diffuseTexColor.a < 0.1) { discard; } // alpha testing
    
    return diffuseTexColor;
}

void main() {
    color = diffuseTexColor();
}
