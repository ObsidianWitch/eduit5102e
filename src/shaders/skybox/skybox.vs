#version 330 core

layout (location = 0) in vec3 position;

out vec3 fsTextureCoords;

uniform mat4 view;
uniform mat4 projection;

void main() {
    // Sets the position in clip space, and sets the z component to the
    // maximum depth (1.0).
    gl_Position = (projection * view * vec4(position, 1.0f)).xyww;
    
    fsTextureCoords = position;
}
