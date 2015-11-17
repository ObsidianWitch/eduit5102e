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
in mat3 fsWorldTBN;

uniform Material material;

vec3 getNormal() {
    if (!material.normalMapIsSet) { return normalize(fsNormal); }
    
    // retrieve normal information in the texture color (range [0,1])
    vec3 normal = texture(material.normalMap, fsTextureCoords).rgb;
    
    // normal in range [-1, 1]
    normal = normalize(normal * 2.0 - 1.0);
    
    // normal from tangent space to world space
    return normalize(fsWorldTBN * normal);
}

vec4 diffuseTexColor() {
    vec4 diffuseTexColor = texture(material.diffuseMap, fsTextureCoords);
    if (diffuseTexColor.a < 0.1) { discard; } // alpha testing
    
    return diffuseTexColor;
}
