#include "Mesh.hpp"

#include <iostream>

Mesh::Mesh(
    const aiMesh* mesh, const aiMaterial* material, std::string directory
) {
    // Vertex
    for (unsigned int i = 0 ; i < mesh->mNumVertices ; i++) {
        Vertex vertex(
            mesh->mVertices[i],
            mesh->mNormals[i],
            mesh->mTextureCoords[0][i]
        );
        vertices.push_back(vertex);
    }
    
    // Indices
    for (unsigned int i = 0 ; i < mesh->mNumFaces ; i++) {
        const aiFace& face = mesh->mFaces[i];
        
        for (unsigned int j = 0 ; j < face.mNumIndices ; j++) {
            indices.push_back(face.mIndices[j]);
        }
    }
    
    // Textures
    if (material->GetTextureCount(aiTextureType_DIFFUSE) > 0) {
        aiString textureFile;
        material->GetTexture(aiTextureType_DIFFUSE, 0, &textureFile);
        
        std::string texturePath = directory + '/' + std::string(textureFile.C_Str());
        textures.push_back(Texture(
            texturePath, GL_TEXTURE0
        ));
    }
    
    createBuffers();
}

void Mesh::createBuffers() {
    // Generate and bind vertex array
    glGenVertexArrays(1, &vertexArray);
    glBindVertexArray(vertexArray);
    
    // Generate and bind index buffer
    GLuint indexBuffer;
    glGenBuffers(1, &indexBuffer);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer);
    glBufferData(
        GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(GLuint),
        &indices.front(), GL_STATIC_DRAW
    );
    
    // Generate and bind Vertex buffer
    GLuint vertexBuffer;
    glGenBuffers(1, &vertexBuffer);
    glBindBuffer(GL_ARRAY_BUFFER, vertexBuffer);
    glBufferData(
        GL_ARRAY_BUFFER, vertices.size() * sizeof(Vertex),
        &vertices.front(), GL_STATIC_DRAW
    );
    
    // Vertex attribute pointers
    Vertex::positionAttribPointer();
    Vertex::normalAttribPointer();
    Vertex::textureCoordAttribPointer();
    
    // Unbind array & buffers
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

void Mesh::draw() {
    for (Texture& texture : textures) {
        texture.bind();
    }
    
    glBindVertexArray(vertexArray);
    
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    
    glBindVertexArray(0);
    
    for (Texture& texture : textures) {
        texture.unbind();
    }
}
