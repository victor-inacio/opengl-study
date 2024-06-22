//
//  Mesh.cpp
//  opengl-study
//
//  Created by Victor Soares on 11/06/24.
//

#include "Mesh.hpp"
#include <iostream>
using namespace std;

Mesh::Mesh(vector<Vector3>& vertices, vector<Vector3>& normals, vector<Vector3>& texCoords) {
    setVertices(vertices);
    setNormals(normals);
    setTexCoords(texCoords);
    setIndices(indices);
}

void Mesh::setVertices(const vector<Vector3>& vertices) {
    this->vertices = vertices;
}

void Mesh::setIndices(const vector<int>& indices) {
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

void Mesh::setNormals(const vector<Vector3> & normals) {
    this->normals = normals;
}

void Mesh::setTexCoords(const vector<Vector3> & texCoords) {
    this->texCoords = texCoords;
}
