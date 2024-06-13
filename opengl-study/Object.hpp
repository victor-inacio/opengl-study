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
   
    Shader shader;
    GLuint VAO;
    GLuint VBO;
    GLuint EBO;
    
    Object(Mesh, Shader);
    ~Object();
    
    void render();
    void setShader(Shader);
    void setMesh(Mesh);
private:
    Mesh mesh;
};

#endif /* Object_hpp */
