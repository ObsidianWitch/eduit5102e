#include <iostream>
#include <fstream>
#include <sstream>
#include <glm/gtc/type_ptr.hpp>
#include "ShaderProgram.hpp"

ShaderProgram::ShaderProgram() {}

ShaderProgram& ShaderProgram::add(GLenum type, std::string filename) {
    std::string str = readShader(filename);
    const GLchar* shaderCode = str.c_str();

    GLuint shader = glCreateShader(type);
    glShaderSource(shader, 1, &shaderCode, NULL);
    glCompileShader(shader);
    
    GLint compiled;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);
    if (!compiled) {
        compilationErrors(shader);
        exit(EXIT_FAILURE);
    }
    
    shaders.push_back(shader);
    
    return *this;
}

std::string ShaderProgram::readShader(std::string filename) {
    std::ifstream ifs(filename, std::ifstream::in);
    
    if (!ifs) {
        std::cerr << "Unable to Open File " << filename << std::endl;
        exit(EXIT_FAILURE);
    }
    
    std::stringstream ss;
    ss << ifs.rdbuf();
    ifs.close();

    return ss.str();
}

void ShaderProgram::link() {
    program = glCreateProgram();
    
    for (GLuint shader : shaders) {
        glAttachShader(program, shader);
    }
    glLinkProgram(program);
    
    GLint linked;
    glGetProgramiv(program, GL_LINK_STATUS, &linked);
    if (!linked) {
        linkageErrors();
        exit(EXIT_FAILURE);
    }
}

void ShaderProgram::use() {
    glUseProgram(program);
}

void ShaderProgram::compilationErrors(GLint shader) {
    GLint length;
    
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &length);
    GLchar* log = new GLchar[length + 1];
    
    glGetShaderInfoLog(shader, length, &length, log);
    std::cout << "Compile Error, Log Below" << std::endl
              << log << std::endl;
    
    delete[] log;
}

void ShaderProgram::linkageErrors() {
    GLint length;
    
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &length);
    GLchar* log = new GLchar[length + 1];
    
    glGetProgramInfoLog(program, length, &length, log);
    std::cout << "Compile Error, Log Below" << std::endl
         << log << std::endl;
    
    delete[] log;
}

GLuint ShaderProgram::uniformLocation(std::string uniformName) {
    return glGetUniformLocation(program, uniformName.c_str());
}

void ShaderProgram::setUniform(GLuint id, GLuint value) {
    glUniform1i(id, value);
}

void ShaderProgram::setUniform(GLuint id, GLfloat value) {
    glUniform1f(id, value);
}

void ShaderProgram::setUniform(GLuint id, const glm::vec3& value) {
    glUniform3fv(id, 1, glm::value_ptr(value));
}

void ShaderProgram::setUniform(GLuint id, const glm::mat3& value) {
    glUniformMatrix3fv(id, 1, GL_FALSE, glm::value_ptr(value));
}

void ShaderProgram::setUniform(GLuint id, const glm::mat4& value) {
    glUniformMatrix4fv(id, 1, GL_FALSE, glm::value_ptr(value));
}
