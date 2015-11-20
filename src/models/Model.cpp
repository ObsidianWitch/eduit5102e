#include <iostream>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/matrix_inverse.hpp>
#include <assimp/Importer.hpp>
#include <assimp/scene.h>
#include <assimp/postprocess.h>

#include "tools/LocalBasis.hpp"
#include "models/Model.hpp"

Model::Model(std::string path) {
    Assimp::Importer importer;
    const aiScene* scene = importer.ReadFile(
        path,
        aiProcess_GenNormals
        | aiProcess_FlipUVs
        | aiProcess_CalcTangentSpace
    );
    if (!scene) {
        std::cerr << "Error loading model: " << importer.GetErrorString()
                  << std::endl;
        exit(EXIT_FAILURE);
    }
    
    meshes = std::make_shared<std::vector<Mesh>>();
    std::string directory = path.substr(0, path.find_last_of('/'));
    for (unsigned int i = 0 ; i < scene->mNumMeshes ; i++) {
        aiMesh* mesh = scene->mMeshes[i];
        
        meshes->push_back(Mesh(
            *mesh,
            *scene->mMaterials[mesh->mMaterialIndex],
            directory
        ));
    }
}

void Model::draw(Shader& shader) {
    for (Mesh& mesh : *meshes) {
        mesh.draw(shader);
    }
}

Model& Model::translate(const glm::vec3& vec) {
    modelMatrix = glm::translate(modelMatrix, vec);
    return *this;
}

/**
 * Rotates the model around its own y axis and the specified angle in radians.
 */
Model& Model::rotate(float angle) {
    return rotate(angle, LocalBasis::y);
}

Model& Model::rotate(float angle, glm::vec3 axis) {
    modelMatrix = glm::rotate(modelMatrix, angle, axis);
    return *this;
}

Model& Model::scale(const glm::vec3& vec) {
    modelMatrix = glm::scale(modelMatrix, vec);
    return *this;
}


glm::mat4 Model::getModelMatrix() { return modelMatrix * transformation; }

/**
 * Computes the normalMatrix from the model matrix. This matrix is used to
 * transform a normal from local to world coordinates. Directly using the
 * Model matrix to do the transformation would cause problems in case of
 * non-uniform scaling.
 */
glm::mat3 Model::getNormalMatrix() {
    return Model::getNormalMatrix(getModelMatrix());
}

glm::mat3 Model::getNormalMatrix(const glm::mat4& pModelMatrix) {
    return glm::mat3(glm::inverseTranspose(pModelMatrix));
}

/**
 * Sets the model's position by overriding the translation column from the
 * model matrix.
 */
Model& Model::setPosition(const glm::vec3& position) {
    modelMatrix[3] = glm::vec4(position, 1.0f);
    return *this;
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

/**
 * Sets the transformation matrix. This matrix is used to apply temporary
 * transformations to the model (e.g. to modify the model over time).
 */
Model& Model::setTransformation(const glm::mat4& transformation) {
    this->transformation = transformation;
    return *this;
}
