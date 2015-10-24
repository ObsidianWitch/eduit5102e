#include <iostream>
#include <fstream>
#include <sstream>
#include <GL/glew.h>
#include <glm/glm.hpp>

#include "Object3D.hpp"

Object3D::Object3D(std::string filename) {
    readMesh(filename);
}

void Object3D::readMesh(std::string filename) {
    std::vector<glm::vec3> vertices;
    std::vector<glm::vec3> normals;
    std::vector<GLuint> indices;
    
    std::ifstream ifs(filename.c_str(), std::ios::in);
    
    if (!ifs) {
        std::cerr << filename << " does not exist." << std::endl;
        exit(1);
    }
    
    std::string line;
    while (getline(ifs, line)) {
        std::stringstream ss(line);
        
        std::string elementType;
        ss >> elementType;
        
        if (elementType == "v") {
            glm::vec3 v;
            ss >> v.x;
            ss >> v.y;
            ss >> v.z;
            glm::normalize(v);
            vertices.push_back(v);
        }
        else if (elementType == "f") {
            GLuint value;
            while(ss >> value) {
                value--;
                indices.push_back(value);
            }
        }
        else if (elementType == "vn") {
            glm::vec3 vn;
            ss >> vn.x;
            ss >> vn.y;
            ss >> vn.z;
            glm::normalize(vn);
            normals.push_back(vn);
        }
    }
    
    mesh.initialize(vertices, normals, indices);
}

void Object3D::draw() {
    mesh.draw();
}
