#ifndef FOREST_HPP
#define FOREST_HPP

#include <vector>

#include "entities/objects/BgObject.hpp"

class Forest {
public:
    Forest(float radius, unsigned int nTrees);
    
    std::vector<BgObject*>& getBgObjects();
    
private:
    std::vector<BgObject*> bgObjects;
    std::vector<BgObject> trees;
    std::vector<BgObject> cliffs;
    BgObject ground;
    float radius;
    
    void createCliffs();
    void generateTrees(unsigned int nTrees);
};

#endif // FOREST_HPP
