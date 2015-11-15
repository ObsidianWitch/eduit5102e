#include "TestBoundingBox.hpp"

TestBoundingBox::TestBoundingBox() {
    shader.add(GL_VERTEX_SHADER, "src/tests/collisions/boundingBox.vs")
              .add(GL_GEOMETRY_SHADER, "src/tests/collisions/boundingBox.gs")
              .add(GL_FRAGMENT_SHADER, "src/tests/collisions/boundingBox.fs")
              .link();
    
    glGenVertexArrays(1, &vertexArray);
    glBindVertexArray(vertexArray);
    glBindVertexArray(0);
}

void TestBoundingBox::update(const BoundingBox& b) {
    shader.setUniform("boundingBox.minPos", b.minPos);
    shader.setUniform("boundingBox.maxPos", b.maxPos);
    
    glBindVertexArray(vertexArray);
    glDrawArrays(GL_POINTS, 0, 1);
    glBindVertexArray(0);
}

Shader& TestBoundingBox::getShader() { return shader; }
