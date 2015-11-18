#ifndef TREE_HPP
#define TREE_HPP

#include <random>
#include <glm/glm.hpp>

#include "entities/objects/Tree.hpp"
#include "entities/objects/BgObject.hpp"

class Tree : public BgObject {
public:
    Tree(const glm::vec3& position, const glm::vec3& scale, float phaseShift);
    Tree(const Tree& tree, float phaseShift);
    
    void update() override;
    
private:
    float phaseShift;
};

#endif // TREE_HPP
