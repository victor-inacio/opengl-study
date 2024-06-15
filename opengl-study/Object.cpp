//
//  Object.cpp
//  opengl-study
//
//  Created by Victor Soares on 11/06/24.
//

#include "Object.hpp"

Object::Object(Mesh& mesh, Shader& shader): mesh(mesh), shader(shader) {
    
    viewMatrix = Matrix4::identity();
    
    glGenVertexArrays(1, &VAO);
    glBindVertexArray(VAO);
    
    glGenBuffers(1, &VBO);
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    
    glGenBuffers(1, &EBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
    glEnableVertexAttribArray(0);
    
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
    
    float vertices[3 * this->mesh.vertices.size()];
    
    
    int index = 0;
    
    for (Vector3 vec : this->mesh.vertices) {
        vertices[index] = vec.x;
        vertices[index + 1] = vec.y;
        vertices[index + 2] = vec.z;
        
        index += 3;
    }
   
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
    
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(this->mesh.indices[0]) * this->mesh.indices.size(), &this->mesh.indices[0], GL_STATIC_DRAW);
}

void Object::render() {
    shader.use();
    shader.setMat4("transform", viewMatrix);
    glBindVertexArray(VAO);
    
    glBindBuffer(GL_ARRAY_BUFFER, VBO);
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
    glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
}

Mesh& Object::getMesh() {
    return mesh;
}










