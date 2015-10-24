#ifndef MODEL_HPP
#define MODEL_HPP

#include <vector>
#include "Mesh.hpp"

class Model {
public:
    Model(std::string path);
    
    void draw();
    
private:
    std::vector<Mesh> meshes;
    
    void loadModel(std::string path);
};


#endif // MODEL_HPP
