#ifndef MODEL_HPP
#define MODEL_HPP

#include <vector>
#include "Mesh.hpp"
#include <glm/mat4x4.hpp>

class Model {
public:
    Model(std::string path);
    
    void draw();
    
    glm::mat4 getModelMatrix();
    void setModelMatrix(glm::mat4 modelMatrix) ;
    
private:
    std::vector<Mesh> meshes;
    glm::mat4 modelMatrix;
    
    void loadModel(std::string path);
};


#endif // MODEL_HPP
