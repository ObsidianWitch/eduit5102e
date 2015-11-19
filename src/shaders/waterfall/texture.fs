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

in vec3 fsNormal;
in vec2 fsTextureCoords;

uniform Material material;
uniform float time;

vec3 getNormal() {
    return normalize(fsNormal);
}

vec4 diffuseTexColor() {
    vec2 rotatingTexCoords = fsTextureCoords;
    rotatingTexCoords.y -= 0.5f * time;
    
    vec4 diffuseTexColor = texture(material.diffuseMap, rotatingTexCoords);
    if (diffuseTexColor.a < 0.1) { discard; } // alpha testing
    
    return diffuseTexColor;
}
