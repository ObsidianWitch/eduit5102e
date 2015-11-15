#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 textureCoords;

out vec3 fsPosition;
out vec3 fsNormal;
out vec2 fsTextureCoords;

uniform mat4 model;
uniform mat3 normalMatrix;
uniform mat4 view;
uniform mat4 projection;

uniform float time;
uniform bool breathing;

void main() {
    mat4 transformedModel = model;
    if (breathing) {
        transformedModel[1].y += 0.005 * exp(sin(time));
    }
    
    gl_Position = projection * view * transformedModel * vec4(position, 1.0f);
    
    fsPosition = vec3(transformedModel * vec4(position, 1.0f));
    fsNormal = normalMatrix * normal;
    fsTextureCoords = textureCoords;
}
