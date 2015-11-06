#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "Model.hpp"

Model::Model(std::string path) {
    loadModel(path);
}

void Model::loadModel(std::string path) {
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(path, aiProcess_GenNormals);
    
    if (!scene) {
        std::cerr << "Error loading model: " << importer.GetErrorString()
                  << std::endl;
    }
    
    for (unsigned int i = 0 ; i < scene->mNumMeshes ; i++) {
        Mesh m(scene->mMeshes[i]);
        meshes.push_back(m);
    }
}

void Model::draw() {
    for (Mesh mesh : meshes) {
        mesh.draw();
    }
}

void Model::translate(const glm::vec3& vec) {
    modelMatrix *= glm::translate(glm::mat4(), vec);
}

/**
 * Rotates the model around its own y axis and the specified angle in radians.
 */
void Model::rotate(float angle) {
    glm::vec3 localUp = glm::vec3(0.0f, 1.0f, 0.0f);
    
    modelMatrix *= glm::rotate(glm::mat4(), angle, localUp);
}

glm::mat4 Model::getModelMatrix() { return modelMatrix; }
