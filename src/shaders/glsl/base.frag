#version 330 core

in vec2 fsTextureCoords;

out vec4 color;

uniform sampler2D diffuseTexture;

void main() {
    color = texture(diffuseTexture, fsTextureCoords);
}
