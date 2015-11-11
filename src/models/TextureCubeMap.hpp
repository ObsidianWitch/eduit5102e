#ifndef TEXTURE_CUBE_MAP_HPP
#define TEXTURE_CUBE_MAP_HPP

#include <GL/glew.h>

class TextureCubeMap {
public:
    TextureCubeMap(const std::vector<std::string>& texturesPaths);
    
    void bind();
    void unbind();
    
private:
    GLuint id;
    
    void load(const std::vector<std::string>& texturesPaths);
    void setParameters();
};

#endif // TEXTURE_CUBE_MAP_HPP
