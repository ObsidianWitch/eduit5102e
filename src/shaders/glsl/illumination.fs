#version 330 core

struct Material {
    sampler2D diffuse;
    float kAmbient;
    float kDiffuse;
    float kSpecular;
    float shininess;
};

struct DirectionalLight {
    vec3 direction;
    vec3 color;
};

in vec3 fsPosition;
in vec3 fsNormal;
in vec2 fsTextureCoords;

uniform vec3 cameraPosition;
uniform DirectionalLight dL;
uniform Material material;

vec3 computeDirectionalLight(DirectionalLight light) {
    vec3 diffuseTexColor = vec3(texture(material.diffuse, fsTextureCoords));
    
    vec3 normal = normalize(fsNormal);
    vec3 lightDirection = normalize(-light.direction);
    vec3 viewDirection = normalize(cameraPosition - fsPosition);
    vec3 reflectedDirection = reflect(-lightDirection, normal);
    
    // Ambient component
    vec3 ambient = light.color * material.kAmbient * diffuseTexColor;
    
    // Diffuse component
    float diffuseCoeff = max(dot(normal, lightDirection), 0.0);
    vec3 diffuse = light.color * material.kDiffuse * diffuseCoeff
                 * diffuseTexColor;
    
    // Specular component
    float specularCoeff = max(dot(viewDirection, reflectedDirection), 0.0);
    vec3 specular = light.color * material.kSpecular
                  * pow(specularCoeff, material.shininess);
    
    return ambient + diffuse + specular;
}

vec3 illumination() {
    return computeDirectionalLight(dL);
}
