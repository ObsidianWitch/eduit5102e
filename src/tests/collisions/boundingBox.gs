#version 330 core

struct BoundingBox {
    vec3 minPos;
    vec3 maxPos;
};

layout (points) in;
layout (triangle_strip, max_vertices = 36) out;

uniform mat4 view;
uniform mat4 projection;
uniform BoundingBox boundingBox;

vec4[8] getPositions() {
    vec4 m = vec4(boundingBox.minPos, 1.0f);
    vec4 M = vec4(boundingBox.maxPos, 1.0f);
    
    return vec4[8](
        vec4(m.x, m.y, m.z, 1.0),
        vec4(M.x, m.y, m.z, 1.0),
        vec4(m.x, M.y, m.z, 1.0),
        vec4(M.x, M.y, m.z, 1.0),
        
        vec4(m.x, m.y, M.z, 1.0),
        vec4(M.x, m.y, M.z, 1.0),
        vec4(m.x, M.y, M.z, 1.0),
        vec4(M.x, M.y, M.z, 1.0)
    );
}
vec4 positions[8] = getPositions();
mat4 pv = projection * view;

void createTriangle(int i1, int i2, int i3) {
    gl_Position = pv * positions[i1]; EmitVertex();
    gl_Position = pv * positions[i2]; EmitVertex();
    gl_Position = pv * positions[i3]; EmitVertex();
    EndPrimitive();
}

void createBoundingBox() {
    createTriangle(0, 1 ,2);
    createTriangle(1, 2, 3);
    
    createTriangle(2, 3, 6);
    createTriangle(3, 6, 7);
    
    createTriangle(4, 5, 6);
    createTriangle(5, 6, 7);
    
    createTriangle(0, 1, 4);
    createTriangle(1, 4, 5);
    
    createTriangle(1, 5, 3);
    createTriangle(5, 3, 7);
    
    createTriangle(0, 4, 2);
    createTriangle(4, 2, 6);
}

void main() {
    createBoundingBox();
}
