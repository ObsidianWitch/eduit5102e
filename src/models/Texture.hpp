#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <string>
#include <vector>
#include <GL/glew.h>
#include <assimp/material.h>

class Texture {
public:
    Texture(std::string path, GLenum unit);
    
    std::string getPath();
    void bind();
    void unbind();
    
    bool operator==(const std::string& str) const;
    
private:
    static std::vector<Texture> loadedTextures;
    
    GLuint id;
    std::string path;
    GLenum unit;
    
    void load(std::string path);
    void setParameters();
};

#endif // TEXTURE_HPP
