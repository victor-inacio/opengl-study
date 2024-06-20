//
//  Object.cpp
//  opengl-study
//
//  Created by Victor Soares on 11/06/24.
//

#include "Object.hpp"
#include <iostream>
using namespace std;
Object::Object(Mesh mesh, Shader& shader): mesh(mesh), shader(shader) {
    
    viewMatrix = Matrix4::identity();
    perspectiveMatrix = Matrix4::identity();
    
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(float), (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    
    setMesh(mesh);
    setShader(shader);
}

Object::~Object() {
    GLuint array[2] = { VAO, VBO };
    glDeleteBuffers(2, array);
}

void Object::setShader(Shader& shader) {
    this->shader = shader;
}

void Object::setMesh(Mesh& mesh) {
    this->mesh = mesh;
    
    float vertices[6 * this->mesh.vertices.size()];
    
    int index = 0;
    
    
    for (Vector3 vec : this->mesh.vertices) {
        vertices[index] = vec.x;
        vertices[index + 1] = vec.y;
        vertices[index + 2] = vec.z;
        
        index += 6;
    }
    
    index = 3;
    for (Vector3 normal : this->mesh.normals) {
        vertices[index] = normal.x;
        vertices[index + 1] = normal.y;
        vertices[index + 2] = normal.z;
        
        index += 6;
    }
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->mesh.indices[0]) * this->mesh.indices.size(), &this->mesh.indices[0], GL_STATIC_DRAW);
    
    glBindVertexArray(0);
    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
    
}

void Object::render() {
    shader.use();
    
    shader.setMat4("modelMatrix", viewMatrix);
    shader.setMat4("perspectiveMatrix", perspectiveMatrix);
    
    glBindVertexArray(VAO);
    glDrawArrays(GL_TRIANGLES, 0, getMesh().vertices.size());
    
    glBindVertexArray(0);
}

Mesh& Object::getMesh() {
    return mesh;
}










