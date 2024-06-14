//
//  Shader.hpp
//  opengl-study
//
//  Created by Victor Soares on 10/06/24.
//

#ifndef Shader_hpp
#define Shader_hpp

#include <stdio.h>
#include <fstream>
#define GL_SILENCE_DEPRECATION
#include <GLFW/glfw3.h>
#include <OpenGL/gl3.h>
#include "Vector3.hpp"
#include "Matrix4.hpp"


using namespace std;

class Shader {
public:
    
    GLuint programID;
    Shader(const string, const string);
    ~Shader();
    
    void use();
    
    void checkPossibleErrors(const GLuint, const string) const;
    
    void setVec3(string, Vector3&) const;
    void setMat4(string, Matrix4&) const;
    
private:    
};

#endif /* Shader_hpp */
