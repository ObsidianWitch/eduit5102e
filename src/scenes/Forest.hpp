#ifndef FOREST_HPP
#define FOREST_HPP

#include <vector>
#include <random>

#include "entities/objects/BgObject.hpp"
#include "entities/objects/Tree.hpp"

class Forest {
public:
    Forest(float radius, unsigned int nTrees);
    
    void update();
    
    std::vector<BgObject*>& getBgObjects();
    
private:
    std::vector<BgObject*> bgObjects;
    std::vector<Tree> trees;
    std::vector<BgObject> cliffs;
    BgObject ground;
    float radius;
    std::mt19937 randomGen;
    
    void createCliffs();
    void generateTrees(unsigned int nTrees);
};

#endif // FOREST_HPP
