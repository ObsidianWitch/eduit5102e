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
    
    Model& translate(const glm::vec3& vec);
    Model& rotate(float angle);
    Model& scale(const glm::vec3& vec);
    
    glm::mat4 getModelMatrix();
    glm::mat3 getNormalMatrix();
    static glm::mat3 getNormalMatrix(const glm::mat4& pModelMatrix);
    glm::vec3 getPosition();
    Model& setPosition(const glm::vec3& position);
    Model& setTransformation(const glm::mat4& transformation);
    
private:
    std::shared_ptr<std::vector<Mesh>> meshes; // allow shallow copy
    glm::mat4 modelMatrix;
    glm::mat4 transformation;
};


#endif // MODEL_HPP
