#version 330 core

struct Material {
    sampler2D diffuse;
    vec4 cAmbient;
    vec4 cDiffuse;
    vec4 cSpecular;
    float shininess;
};

in vec3 fsPosition;
in vec3 fsNormal;
in vec2 fsTextureCoords;

uniform vec3 cameraPosition;
uniform Material material;

vec3 normal = normalize(fsNormal);

vec4 diffuseTexColor() {
    vec4 diffuseTexColor = texture(material.diffuse, fsTextureCoords);
    if (diffuseTexColor.a < 0.1) { discard; } // alpha testing
    
    return diffuseTexColor;
}

vec4 ambientComponent(vec4 lightColor) {
    return lightColor * material.cAmbient * diffuseTexColor();
}

vec4 diffuseComponent(vec4 lightColor, vec3 lightDirection) {
    float diffuseCoeff = max(dot(normal, lightDirection), 0.0);
    return lightColor * material.cDiffuse * diffuseCoeff * diffuseTexColor();
}

vec4 specularComponent(vec4 lightColor, vec3 lightDirection) {
    vec3 viewDirection = normalize(cameraPosition - fsPosition);
    vec3 reflectedDirection = reflect(-lightDirection, normal);
    
    float specularCoeff = pow(
        max(dot(viewDirection, reflectedDirection), 0.0),
        material.shininess
    );
    return lightColor * material.cSpecular * specularCoeff;
}
