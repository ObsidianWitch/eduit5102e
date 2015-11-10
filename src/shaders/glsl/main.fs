#version 330 core

out vec4 color;

vec3 illumination();

void main() {
    color = vec4(illumination(), 1.0);
}
