//
//  Mesh.cpp
//  opengl-study
//
//  Created by Victor Soares on 11/06/24.
//

#include "Mesh.hpp"
#include <iostream>
using namespace std;

Mesh::Mesh(vector<Vector3>& vertices, vector<int>& indices) {
    setVertices(vertices);
    setIndices(indices);
}

void Mesh::setVertices(vector<Vector3>& vertices) {
    this->vertices = vertices;
}

void Mesh::setIndices(vector<int>& indices) {
    this->indices = indices;
}

void Mesh::printVertices() const {
    int index = 0;
    for (Vector3 vec : vertices) {
        cout << index + 1 << ": ";
        vec.print();
        
        index++;
    }
}

void Mesh::printTransformedVertices(const Matrix4& matrix) const{
    int index = 0;
    for (Vector3 vec : vertices) {
        Vector3 transformed = matrix * vec;
        cout << index + 1 << ": ";
        transformed.print();
        
        index++;
    }
}

