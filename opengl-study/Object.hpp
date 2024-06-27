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
#include "Matrix4.hpp"
#include "Texture.hpp"
#include "Transform.hpp"
#include <GLFW/glfw3.h>
#include <OpenGL/gl.h>
#include <optional>

class Object {
    
public:
    Shader shader;
    GLuint VAO;	
    GLuint VBO;
    GLuint EBO;

    Matrix4 perspectiveMatrix;
    Matrix4 viewMatrix;
    Transform transform = Transform();
    
    optional<Texture> texture;
    
    Object(Mesh, Shader&);
    ~Object();
    
    Mesh& getMesh();
    
    void render();
    void setShader(Shader&);
    void setMesh(Mesh&);
    void setTexture(const Texture&);
    
    Matrix4 getModelMatrix() const;
    
    static Object cube(Shader);
    
private:
    Mesh mesh;
};

#endif /* Object_hpp */
