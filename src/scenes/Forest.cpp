#include <random>
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>

#include "scenes/Forest.hpp"

Forest::Forest(float radius, unsigned int nTrees) :
    ground(
        "resources/ground/ground.obj",     // file path
        glm::vec3(0.0f),                   // position
        glm::vec3(1000.0f, 1.0f, 1000.0f), // scaling vector
        BoundingBox(                       // bounding box
            glm::vec3(0.0f),
            glm::vec3(0.0f)
        ),
        false                              // silhouette
    ),
    radius(radius)
{
    trees.reserve(nTrees);
    generate();
    
    bgObjects.reserve(1 + trees.size());
    bgObjects.push_back(&ground);
    for (auto& t : trees) { bgObjects.push_back(&t); }
}

void Forest::generate() {
    BgObject tree(
        "resources/tree1/Forest_tree.obj",                // file path
        glm::vec3(0.0f, 0.0f, 0.0f),                      // position
        glm::vec3(10.0f),                                 // scaling vector
        BoundingBox(glm::vec3(-10.0f), glm::vec3(10.0f)), // bounding box
        false                                             // silhouette
    );
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<float> dRadius(30.0f, this->radius);
    std::uniform_real_distribution<float> dAngle(0, glm::two_pi<float>());
    for (unsigned int i = 0 ; i < trees.capacity() ; i++) {
        float radius = dRadius(gen);
        float angle = dAngle(gen);
        
        trees.push_back(BgObject(
            tree, glm::vec3(
                radius * cos(angle),
                0.0f,
                radius * sin(angle)
            )
        ));
    }
}

std::vector<BgObject*>& Forest::getBgObjects() { return bgObjects; }
