//
//  Object.cpp
//  opengl-study
//
//  Created by Victor Soares on 11/06/24.
//

#include "Object.hpp"

Object::Object(Mesh mesh, Shader shader): mesh(mesh), shader(shader) {
    
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    
    
    setMesh(mesh);
    setShader(shader);
}

Object::~Object() {
    GLuint array[2] = { VAO, VBO };
    glDeleteBuffers(2, array);
}

void Object::setShader(Shader shader) {
    this->shader = shader;
}

void Object::setMesh(Mesh mesh) {
    this->mesh = mesh;
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(this->mesh.vertices[0]) * this->mesh.vertices.size(), &this->mesh.vertices[0], GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->mesh.indices[0]) * this->mesh.indices.size(), &this->mesh.indices[0], GL_STATIC_DRAW);
}

void Object::render() {
    shader.use();
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_VERTEX_ARRAY, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glDrawElements(GL_TRIANGLES, static_cast<int>(this->mesh.indices.size()), GL_UNSIGNED_INT, 0);
}










