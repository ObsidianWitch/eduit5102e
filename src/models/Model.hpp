#ifndef MODEL_HPP
#define MODEL_HPP

#include <vector>
#include "Mesh.hpp"
#include <glm/glm.hpp>

class Model {
public:
    Model(std::string path);
    
    void draw();
    
    void translate(const glm::vec3& vec);
    
    glm::mat4 getModelMatrix();
    
private:
    std::vector<Mesh> meshes;
    glm::mat4 modelMatrix;
    
    void loadModel(std::string path);
};


#endif // MODEL_HPP
