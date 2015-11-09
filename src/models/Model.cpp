#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "tools/LocalBasis.hpp"
#include "Model.hpp"

Model::Model(std::string path) {
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(
        path, aiProcess_GenNormals | aiProcess_FlipUVs
    );
    if (!scene) {
        std::cerr << "Error loading model: " << importer.GetErrorString()
                  << std::endl;
    }
    
    std::string directory = path.substr(0, path.find_last_of('/'));
    for (unsigned int i = 0 ; i < scene->mNumMeshes ; i++) {
        aiMesh* mesh = scene->mMeshes[i];

        meshes.push_back(Mesh(
            *mesh,
            *scene->mMaterials[mesh->mMaterialIndex],
            directory
        ));
    }
}

void Model::draw(Shader& shader) {
    for (Mesh mesh : meshes) {
        mesh.draw(shader);
    }
}

void Model::translate(const glm::vec3& vec) {
    modelMatrix *= glm::translate(glm::mat4(), vec);
}

/**
 * Rotates the model around its own y axis and the specified angle in radians.
 */
void Model::rotate(float angle) {
    modelMatrix *= glm::rotate(glm::mat4(), angle, LocalBasis::y);
}

glm::mat4 Model::getModelMatrix() { return modelMatrix; }
