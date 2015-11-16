#version 330 core

in vec3 fsTextureCoords;

out vec4 color;

uniform samplerCube skyboxBack;
uniform samplerCube skyboxFront;
uniform mat4 rotationMatrix;

void main() {
    vec4 backColor = texture(skyboxBack, fsTextureCoords);
    
    vec4 frontColor = texture(
        skyboxFront,
        vec3(rotationMatrix * vec4(fsTextureCoords, 1.0))
    );
    
    color = (frontColor.a < 0.2)
          ? backColor
          : frontColor * 0.5 + backColor * 0.5;
}
