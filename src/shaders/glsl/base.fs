#version 330 core

in vec2 fsTextureCoords;

out vec4 color;

uniform sampler2D diffuseTexture;

vec4 ambient();

void main() {
    vec4 textureColor = texture(diffuseTexture, fsTextureCoords);
    
    color = textureColor * ambient();
}
