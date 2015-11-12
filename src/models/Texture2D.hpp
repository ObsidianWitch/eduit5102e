#ifndef TEXTURE_2D_HPP
#define TEXTURE_2D_HPP

#include <string>
#include <vector>
#include <GL/glew.h>

class Texture2D {
public:
    Texture2D(std::string path, GLenum unit);
    
    void bind();
    void unbind();
    
    bool operator==(const std::string& str) const;
    
private:
    static std::vector<Texture2D> loadedTextures;
    
    GLuint id;
    std::string path;
    GLenum unit;
    
    void load(std::string path);
    void setParameters();
};

#endif // TEXTURE_2D_HPP
