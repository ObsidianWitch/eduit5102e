#version 330 core

struct AmbientLight {
    vec3 color;
};

struct DirectionalLight {
    vec3 direction;
    vec3 color;
};

struct PointLight {
    vec3 postion;
    vec3 color;
};

in vec3 fsPosition;

uniform AmbientLight aL;
uniform DirectionalLight dL;

vec3 ambientComponent(vec3 lightColor);
vec3 diffuseComponent(vec3 lightColor, vec3 lightDirection);
vec3 specularComponent(vec3 lightColor, vec3 lightDirection);

vec3 computeAmbientLight(AmbientLight light) {
    return ambientComponent(light.color);
}

vec3 computeDirectionalLight(DirectionalLight light) {
    vec3 lightDirection = normalize(-light.direction);
    
    return diffuseComponent(light.color, lightDirection)
         + specularComponent(light.color, lightDirection);
}

vec3 computePointLight(PointLight light) {
    vec3 lightDirection = normalize(light.postion - fsPosition);
    
    return diffuseComponent(light.color, lightDirection)
         + specularComponent(light.color, lightDirection);
}

vec3 illumination() {
    return computeAmbientLight(aL)
         + computeDirectionalLight(dL);
}
