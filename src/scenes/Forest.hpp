#ifndef FOREST_HPP
#define FOREST_HPP

#include <vector>

#include "entities/objects/BgObject.hpp"

class Forest {
public:
    Forest(float radius);
    
    std::vector<BgObject*>& getBgObjects();
    
private:
    std::vector<BgObject*> bgObjects;
    std::vector<BgObject> trees;
    BgObject ground;
    float radius;
    
    void generate();
};

#endif // FOREST_HPP
