#ifndef SCENES_HPP
#define SCENES_HPP

#include <vector>
#include <memory>

#include "entities/Entity.hpp"
#include "entities/player/Player.hpp"
#include "entities/camera/Camera.hpp"
#include "entities/skybox/Skybox.hpp"
#include "entities/objects/BgObject.hpp"
#include "shaders/Shader.hpp"

class Scene {
public:
    Scene(GLuint width, GLuint height);
    
    void update();
    
private:
    std::vector<std::shared_ptr<Entity>> lights;
    std::vector<BgObject> bgObjects;
    Player player;
    Camera camera;
    Skybox skybox;
    
    Shader mainShader;
    Shader skyboxShader;
    
    void addLight(Entity* entity);
    void addBgObject(BgObject& bgObject);
    void updateEntities(Shader& shader);
};

#endif // SCENES_HPP
