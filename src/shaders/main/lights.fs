#version 330 core

struct AmbientLight {
    vec4 color;
};

struct DirectionalLight {
    vec3 direction;
    vec4 color;
};

struct PointLight {
    vec3 postion;
    vec4 color;
};

in vec3 fsPosition;

uniform AmbientLight aL;
uniform DirectionalLight dL;
uniform PointLight pL;

vec4 ambientComponent(vec4 lightColor);
vec4 diffuseComponent(vec4 lightColor, vec3 lightDirection);
vec4 specularComponent(vec4 lightColor, vec3 lightDirection);

vec4 computeAmbientLight(AmbientLight light) {
    return ambientComponent(light.color);
}

vec4 computeDirectionalLight(DirectionalLight light) {
    vec3 lightDirection = normalize(-light.direction);
    
    return diffuseComponent(light.color, lightDirection)
         + specularComponent(light.color, lightDirection);
}

vec4 computePointLight(PointLight light) {
    vec3 lightDirection = normalize(light.postion - fsPosition);
    
    return diffuseComponent(light.color, lightDirection)
         + specularComponent(light.color, lightDirection);
}

vec4 illumination() {
    return computeAmbientLight(aL)
         + computeDirectionalLight(dL)
         + computePointLight(pL);
}
