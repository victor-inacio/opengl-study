//
//  Shader.cpp
//  opengl-study
//
//  Created by Victor Soares on 10/06/24.
//
#include <iostream>
#include <fstream>
#include <sstream>

#include <unistd.h>
#include "Shader.hpp"
using namespace std;

Shader::Shader(string vShaderPath, string fShaderPath) {
    
    
    string vertexCode;
    string fragmentCode;
    ifstream vShaderFile;
    ifstream fShaderFile;
    
    vShaderFile.exceptions( ifstream::badbit | ifstream::failbit );
    fShaderFile.exceptions( ifstream::badbit | ifstream::failbit );
    
    try {
        
        vShaderFile.open(vShaderPath);
        fShaderFile.open(fShaderPath);
        
        stringstream vShaderStream, fShaderStream;
        
        vShaderStream << vShaderFile.rdbuf();
        fShaderStream << fShaderFile.rdbuf();
        
        vShaderFile.clear();
        fShaderFile.clear();
        
        vShaderFile.close();
        fShaderFile.close();
        
        vertexCode = vShaderStream.str();
        fragmentCode = fShaderStream.str();
    } catch(ifstream::failure &e) {
        cout << "Error when reading shader files: " << e.what() << endl;
    }
    
    const char* vShaderCode = vertexCode.c_str();
    const char* fShaderCode = fragmentCode.c_str();
    
    GLuint fragment, vertex;
    vertex = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(vertex, 1, &vShaderCode, NULL);
    glCompileShader(vertex);
    checkPossibleErrors(vertex, "VERTEX");
    
    fragment = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(fragment, 1, &fShaderCode, NULL);
    glCompileShader(fragment);
    checkPossibleErrors(fragment, "FRAGMENT");
    
    programID = glCreateProgram();
    glAttachShader(programID, vertex);
    glAttachShader(programID, fragment);
    glLinkProgram(programID);
    
    checkPossibleErrors(programID, "PROGRAM");
    
    glDeleteShader(vertex);
    glDeleteShader(fragment);
}

Shader::~Shader() {
//    glDeleteProgram(programID);
}

void Shader::use() {
    glUseProgram(programID);
}

void Shader::checkPossibleErrors(const GLuint id, const string type) const {
    
    int success;
    char infoLog[1024];
    
    if (type == "PROGRAM") {
        
        glGetProgramiv(id, GL_LINK_STATUS, &success);
        
        if (!success) {
            glGetProgramInfoLog(id, 1024, NULL, infoLog);
            
            cout << "Error on linking program: " << infoLog << endl;
        }
        
    } else {
        glGetShaderiv(id, GL_COMPILE_STATUS, &success);
        
        if (!success) {
            glGetShaderInfoLog(id, 2024, NULL, infoLog);
            
            cout << "Error on compile shader: " << infoLog << endl;
        }
    }
    
}

void Shader::setVec3(string name, Vector3& vec) const {
    GLint location = glGetUniformLocation(programID, name.c_str());
    glUniform3f(location, vec.x, vec.y, vec.z);
}

void Shader::setMat4(string name, Matrix4& matrix) const {

    GLint location = glGetUniformLocation(programID, name.c_str());
    
    float ptr[16];
    
    for (int j = 0; j < 4; j++) {
        for (int i = 0; i < 4; i++) {
            ptr[4 * j + i] = matrix[i][j];
        }
    }
    
    glUniformMatrix4fv(location, 1, GL_FALSE, ptr);
}
