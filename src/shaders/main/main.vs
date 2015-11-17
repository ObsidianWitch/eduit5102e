#version 330 core

layout (location = 0) in vec3 position;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 textureCoords;
layout (location = 3) in vec3 tangent;
layout (location = 4) in vec3 bitangent;

out vec3 fsPosition;
out vec3 fsNormal;
out vec2 fsTextureCoords;
out mat3 fsWorldTBN;

uniform mat4 model;
uniform mat3 normalMatrix;
uniform mat4 view;
uniform mat4 projection;

/**
 * Computes the world TBN matrix which transforms coordinates from tangent space
 * (e.g. normal maps) to world space.
 */
mat3 computeWorldTBN() {
    return mat3(
        normalize(normalMatrix * tangent),
        normalize(normalMatrix * bitangent),
        normalize(normalMatrix * normal)
    );
}

void main() {
    gl_Position = projection * view * model * vec4(position, 1.0f);
    
    fsPosition = vec3(model * vec4(position, 1.0f));
    fsNormal = normalMatrix * normal;
    fsTextureCoords = textureCoords;
    fsWorldTBN = computeWorldTBN();
}
