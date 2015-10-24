#ifndef MODEL_HPP
#define MODEL_HPP

#include "Mesh.hpp"

class Model {
public:
    Model(std::string filename);
    
    void draw();

private:
    Mesh mesh;
    
    void readMesh(std::string filename);
};


#endif // MODEL_HPP
