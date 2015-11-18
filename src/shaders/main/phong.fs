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

in vec3 fsPosition;

uniform vec3 cameraPosition;
uniform Material material;

vec3 getNormal();
vec4 diffuseTexColor();

vec4 ambientComponent(vec4 lightColor) {
    return lightColor * material.cAmbient * diffuseTexColor();
}

vec4 diffuseComponent(vec4 lightColor, vec3 lightDirection) {
    float diffuseCoeff = max(dot(getNormal(), lightDirection), 0.2);
    return lightColor * material.cDiffuse * diffuseCoeff * diffuseTexColor();
}

vec4 specularComponent(vec4 lightColor, vec3 lightDirection) {
    vec3 viewDirection = normalize(cameraPosition - fsPosition);
    vec3 reflectedDirection = reflect(-lightDirection, getNormal());
    
    float specularCoeff = pow(
        max(dot(viewDirection, reflectedDirection), 0.2),
        material.shininess
    );
    return lightColor * material.cSpecular * specularCoeff;
}
