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

glm::mat4 Model::getModelMatrix() { return modelMatrix; }
