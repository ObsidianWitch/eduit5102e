#include "Mesh.hpp"

#include <iostream>

Mesh::Mesh(
    const aiMesh& mesh, const aiMaterial& material, std::string directory
) :
    material(material, directory)
{
    // Vertex
    for (unsigned int i = 0 ; i < mesh.mNumVertices ; i++) {
        Vertex vertex(
            mesh.mVertices[i],
            mesh.mNormals[i],
            mesh.mTextureCoords[0][i]
        );
        vertices.push_back(vertex);
    }
    
    // Indices
    for (unsigned int i = 0 ; i < mesh.mNumFaces ; i++) {
        const aiFace& face = mesh.mFaces[i];
        
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

void Mesh::draw(Shader& shader) {
    material.update(shader);
    
    material.bindTextures();
    
    glBindVertexArray(vertexArray);
    glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
    glBindVertexArray(0);
    
    material.unbindTextures();
}
