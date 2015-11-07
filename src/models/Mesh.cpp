#include "Mesh.hpp"

Mesh::Mesh(const aiMesh* mesh) {
    // Vertex positions & normals
    for (unsigned int i = 0 ; i < mesh->mNumVertices ; i++) {
        glm::vec3 position = glm::vec3(
            mesh->mVertices[i].x,
            mesh->mVertices[i].y,
            mesh->mVertices[i].z
        );
        vertices.push_back(position);
        
        glm::vec3 normal = glm::vec3(
            mesh->mNormals[i].x,
            mesh->mNormals[i].y,
            mesh->mNormals[i].z
        );
        normals.push_back(normal);
    }
    
    // Indices
    for (unsigned int i = 0 ; i < mesh->mNumFaces ; i++) {
        const aiFace& face = mesh->mFaces[i];
        
        for (unsigned int j = 0 ; j < face.mNumIndices ; j++) {
            indices.push_back(face.mIndices[j]);
        }
    }
    
    createBuffers();
}

void Mesh::createBuffers() {
    // Generate and bind vertex array
    glGenVertexArrays(1, &vertexArray);
    glBindVertexArray(vertexArray);
    
    // Generate and bind index buffer
    glGenBuffers(1, &indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    glBufferData(
        GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint),
        &indices.front(), GL_STATIC_DRAW
    );
    
    // Vertex buffer
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(
        GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3),
        &vertices.front(), GL_STATIC_DRAW
    );
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), 0);
    glEnableVertexAttribArray(0);
    
    // Normal buffer
    glGenBuffers(1, &normalBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, normalBuffer);
    glBufferData(
        GL_ARRAY_BUFFER, normals.size() * sizeof(glm::vec3),
        &normals.front(), GL_STATIC_DRAW
    );
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, sizeof(glm::vec3), 0);
    glEnableVertexAttribArray(1);
    
    // Unbind array & buffers
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Mesh::draw() {
    glBindVertexArray(vertexArray);
    
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    
    glBindVertexArray(0);
}
