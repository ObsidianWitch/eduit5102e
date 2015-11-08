#ifndef MODEL_HPP
#define MODEL_HPP

#include <vector>
#include <glm/glm.hpp>

#include "Mesh.hpp"

class Model {
public:
    Model(std::string path);
    
    void draw();
    
    void translate(const glm::vec3& vec);
    void rotate(float angle);
    
    glm::mat4 getModelMatrix();
    
private:
    std::vector<Mesh> meshes;
    glm::mat4 modelMatrix;
};


#endif // MODEL_HPP
