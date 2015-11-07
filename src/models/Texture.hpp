#ifndef TEXTURE_HPP
#define TEXTURE_HPP

#include <string>
#include <GL/glew.h>

class Texture {
public:
    Texture(std::string path, GLenum unit);
    
    std::string getPath();
    void bind();
    void unbind();
private:
    GLuint id;
    std::string path;
    GLenum unit;
    
    void load(std::string path);
    void setParameters();
};

#endif // TEXTURE_HPP
