#version 330 core

in vec3 fsTextureCoords;

out vec4 color;

uniform samplerCube skybox;
uniform mat4 rotationMatrix;

void main() {
    vec3 rotatingTexCoords = vec3(
        rotationMatrix * vec4(fsTextureCoords, 1.0)
    );
    
    color = texture(skybox, rotatingTexCoords);
}
