#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 textureCoords;

out vec3 fsPosition;
out vec3 fsNormal;
out vec2 fsTextureCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;

void main() {
    gl_Position = projection * view * model * vec4(position, 1.0f);
    
    fsPosition = position;
    fsNormal = normal;
    fsTextureCoords = textureCoords;
}
