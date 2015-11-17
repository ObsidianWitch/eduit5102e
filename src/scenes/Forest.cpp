#include <glm/glm.hpp>

#include "scenes/Forest.hpp"

Forest::Forest(float radius) :
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
    
    for (float x = 30.0f ; x < radius ; x += 1.0f) {
        float z = radius * radius - x * x;
        
        trees.push_back(BgObject(
            tree, glm::vec3(x, 0.0f, 0.0f)
        ));
    }
}

std::vector<BgObject*>& Forest::getBgObjects() { return bgObjects; }
