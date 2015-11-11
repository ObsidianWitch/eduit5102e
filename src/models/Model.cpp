#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>
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
    modelMatrix = glm::translate(modelMatrix, vec);
}

/**
 * Rotates the model around its own y axis and the specified angle in radians.
 */
void Model::rotate(float angle) {
    modelMatrix = glm::rotate(modelMatrix, angle, LocalBasis::y);
}

glm::mat4 Model::getModelMatrix() { return modelMatrix; }

/**
 * Computes the normalMatrix from the model matrix. This matrix is used to
 * transform a normal from local to world coordinates. Directly using the
 * Model matrix to do the transformation would cause problems in case of
 * non-uniform scaling.
 */
glm::mat3 Model::getNormalMatrix() {
    return glm::mat3(glm::inverseTranspose(modelMatrix));
}

/**
 * Retrieves the model's position with the translation column from the model
 * matrix.
 */
glm::vec3 Model::getPosition() {
    return glm::vec3(
        modelMatrix[3][0],
        modelMatrix[3][1],
        modelMatrix[3][2]
    );
}
