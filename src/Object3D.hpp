#ifndef OBJECT3D_HPP
#define OBJECT3D_HPP

#include "Mesh.hpp"

class Object3D {
public:
    Object3D(std::string filename);
    
    void draw();

private:
    Mesh mesh;
    
    void readMesh(std::string filename);
};


#endif // OBJECT3D_HPP
