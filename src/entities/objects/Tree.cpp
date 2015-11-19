#include <ctime>
#include <random>
#include <glm/gtc/constants.hpp>
#include <glm/gtx/transform2.hpp>

#include "entities/objects/Tree.hpp"
#include <GLFW/glfw3.h>

Tree::Tree(
    const glm::vec3& position, const glm::vec3& scale, float phaseShift
) :
    BgObject(
        "resources/tree/Forest_tree.obj", // filepath
        position,
        scale,
        BoundingBox(
            glm::vec3(-10.0f),
            glm::vec3(10.0f)
        )
    ),
    phaseShift(phaseShift)
{}

Tree::Tree(const Tree& tree, float phaseShift) :
    Tree(tree)
{
    this->phaseShift = phaseShift;
}

void Tree::update() {
    model.setTransformation(
        glm::shearX3D(
            glm::mat4(),
            0.005f * (float) sin(phaseShift + glfwGetTime()),
            0.0f
        )
    );
}
