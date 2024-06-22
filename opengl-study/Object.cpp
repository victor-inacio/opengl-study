//
//  Object.cpp
//  opengl-study
//
//  Created by Victor Soares on 11/06/24.
//

#include "Object.hpp"
#include "include/stb_image.h"
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
    
    unsigned int texture;
    glGenTextures(1, &texture);
    glBindTexture(GL_TEXTURE_2D, texture);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_MIRRORED_REPEAT);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_MIRRORED_REPEAT);
    
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR_MIPMAP_LINEAR);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    
    
    
    int width, height, channels;
    unsigned char* data = stbi_load("images/stone.png", &width, &height, &channels, 0);
    
    if (data) {
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, data);
        glGenerateMipmap(GL_TEXTURE_2D);
    } else {
        cout << "Error when loading texture" << endl;
    }
    
    stbi_image_free(data);
    
    GLsizei stride = 8 * sizeof(float);
    
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, stride, (void*)0);
    glEnableVertexAttribArray(0);
    
    glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, stride, (void*)(3 * sizeof(float)));
    glEnableVertexAttribArray(1);
    
    glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, stride, (void*)(6 * sizeof(float)));
    glEnableVertexAttribArray(2);
    
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
    
    float vertices[8 * this->mesh.vertices.size()];
    
    int index = 0;
    int stride = 8;
    
    for (Vector3 vec : this->mesh.vertices) {
        vertices[index] = vec.x;
        vertices[index + 1] = vec.y;
        vertices[index + 2] = vec.z;
        
        index += stride;
    }
    
    index = 3;
    for (Vector3 normal : this->mesh.normals) {
        vertices[index] = normal.x;
        vertices[index + 1] = normal.y;
        vertices[index + 2] = normal.z;
        
        index += stride;
    }
    index = 6;
    for (Vector3 texCoord : this->mesh.texCoords) {
        vertices[index] = texCoord.x;
        vertices[index + 1] = texCoord.y;
        
        index += stride;
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
    glDrawArrays(GL_TRIANGLES, 0, static_cast<GLuint>(getMesh().vertices.size()));
    
    glBindVertexArray(0);
}

Mesh& Object::getMesh() {
    return mesh;
}










