#version 330 core

struct Material {
    sampler2D diffuse;
    vec3 cAmbient;
    vec3 cDiffuse;
    vec3 cSpecular;
    float shininess;
};

struct AmbientLight {
    vec3 color;
};

struct DirectionalLight {
    vec3 direction;
    vec3 color;
};

in vec3 fsPosition;
in vec3 fsNormal;
in vec2 fsTextureCoords;

uniform vec3 cameraPosition;
uniform AmbientLight aL;
uniform DirectionalLight dL;
uniform Material material;

vec3 computeAmbientLight(AmbientLight light) {
    vec3 diffuseTexColor = vec3(texture(material.diffuse, fsTextureCoords));
    
    // Ambient component
    vec3 ambient = light.color * material.cAmbient * diffuseTexColor;
    
    return ambient;
}

vec3 computeDirectionalLight(DirectionalLight light) {
    vec3 diffuseTexColor = vec3(texture(material.diffuse, fsTextureCoords));
    
    vec3 normal = normalize(fsNormal);
    vec3 lightDirection = normalize(-light.direction);
    vec3 viewDirection = normalize(cameraPosition - fsPosition);
    vec3 reflectedDirection = reflect(-lightDirection, normal);
    
    // Diffuse component
    float diffuseCoeff = max(dot(normal, lightDirection), 0.0);
    vec3 diffuse = light.color * material.cDiffuse * diffuseCoeff
                 * diffuseTexColor;
    
    // Specular component
    float specularCoeff = max(dot(viewDirection, reflectedDirection), 0.0);
    vec3 specular = light.color * material.cSpecular
                  * pow(specularCoeff, material.shininess);
    
    return diffuse + specular;
}

vec3 illumination() {
    return computeAmbientLight(aL) + computeDirectionalLight(dL);
}
