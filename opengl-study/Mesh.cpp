//
//  Mesh.cpp
//  opengl-study
//
//  Created by Victor Soares on 11/06/24.
//

#include "Mesh.hpp"

Mesh::Mesh(vector<Vector3> vertices, vector<int> indices) {
    setVertices(vertices);
    setIndices(indices);
}

void Mesh::setVertices(vector<Vector3> vertices) {
    this->vertices = vertices;
}

void Mesh::setIndices(vector<int> indices) {
    this->indices = indices;
}
