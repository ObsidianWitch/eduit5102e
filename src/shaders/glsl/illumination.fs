#version 330 core

vec4 ambient() {
    float kA = 0.2f;
    vec3 lightColor = vec3(1.0f);
    
    return vec4(kA * lightColor, 1.0f);
}
