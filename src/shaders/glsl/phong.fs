#version 330 core

struct Material {
    sampler2D diffuse;
    vec3 cAmbient;
    vec3 cDiffuse;
    vec3 cSpecular;
    float shininess;
};

in vec3 fsPosition;
in vec3 fsNormal;
in vec2 fsTextureCoords;

uniform vec3 cameraPosition;
uniform Material material;

vec3 normal = normalize(fsNormal);
vec3 diffuseTexColor = vec3(texture(material.diffuse, fsTextureCoords));

vec3 computeAmbientComponent(vec3 lightColor) {
    return lightColor * material.cAmbient * diffuseTexColor;
}

vec3 computeDiffuseComponent(vec3 lightColor, vec3 lightDirection) {
    float diffuseCoeff = max(dot(normal, lightDirection), 0.0);
    return lightColor * material.cDiffuse * diffuseCoeff * diffuseTexColor;
}

vec3 computeSpecularComponent(vec3 lightColor, vec3 lightDirection) {
    vec3 viewDirection = normalize(cameraPosition - fsPosition);
    vec3 reflectedDirection = reflect(-lightDirection, normal);
    
    float specularCoeff = max(dot(viewDirection, reflectedDirection), 0.0);
    return lightColor * material.cSpecular
                      * pow(specularCoeff, material.shininess);
}
