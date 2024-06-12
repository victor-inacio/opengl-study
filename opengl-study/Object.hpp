//
//  Object.hpp
//  opengl-study
//
//  Created by Victor Soares on 11/06/24.
//

#ifndef Object_hpp
#define Object_hpp

#include "Mesh.hpp"
#include "Shader.hpp"
#include <GLFW/glfw3.h>
#include <OpenGL/gl.h>


class Object {
    
public:
    Mesh mesh;
    Shader shader;
    GLuint VAO;
    GLuint VBO;
    
    
    Object(Mesh, Shader);
    ~Object();
    
    void render();
    void setShader(Shader);
    
private:
    
};

#endif /* Object_hpp */
