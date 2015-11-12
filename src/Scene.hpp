#ifndef SCENES_HPP
#define SCENES_HPP

#include <vector>

#include "entities/Entity.hpp"
#include "entities/player/Player.hpp"
#include "entities/camera/Camera.hpp"
#include "entities/skybox/Skybox.hpp"
#include "shaders/Shader.hpp"

class Scene {
public:
    Scene(GLuint width, GLuint height);
    
    void update();
    
private:
    std::vector<Entity*> lights;
    Player player;
    Camera camera;
    Skybox skybox;
    
    Shader mainShader;
    Shader skyboxShader;
};

#endif // SCENES_HPP
