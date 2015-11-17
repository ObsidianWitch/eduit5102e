#ifndef MODEL_HPP
#define MODEL_HPP

#include <memory>
#include <vector>
#include <glm/glm.hpp>

#include "shaders/Shader.hpp"
#include "models/Mesh.hpp"

class Model {
public:
    Model(std::string path);
    
    void draw(Shader& shader);
    
    void translate(const glm::vec3& vec);
    void rotate(float angle);
    void scale(const glm::vec3& vec);
    
    glm::mat4 getModelMatrix();
    glm::mat3 getNormalMatrix();
    glm::vec3 getPosition();
    void setPosition(const glm::vec3& position);
    
private:
    std::shared_ptr<std::vector<Mesh>> meshes; // allow shallow copy
    glm::mat4 modelMatrix;
};


#endif // MODEL_HPP
