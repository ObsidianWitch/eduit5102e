#ifndef TEST_BOUNDING_BOX_HPP
#define TEST_BOUNDING_BOX_HPP

#include "shaders/Shader.hpp"
#include "behaviours/collisions/BoundingBox.hpp"

class TestBoundingBox {
public:
    TestBoundingBox();
    
    void update(const BoundingBox& b);
    
    Shader& getShader();
    
private:
    Shader shader;
    GLuint vertexArray;
};

#endif // TEST_BOUNDING_BOX_HPP
