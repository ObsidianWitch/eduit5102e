#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 textureCoords;

out vec2 fsTextureCoords;

uniform mat4 model;
uniform mat4 view;
uniform mat4 projection;
uniform float time;

float cnoise(vec3 P);

void main() {
    float displacement = 10.0 * cnoise(normal + 2 * time);
    
    // displace the upper half of the sphere along the +y local axis
    vec3 newPosition = position;
    newPosition.y = (position.y > 0.0)
                  ? abs(position.y * displacement)
                  : position.y;
    gl_Position = projection * view * model * vec4(newPosition, 1.0);
    
    fsTextureCoords = textureCoords;
}
