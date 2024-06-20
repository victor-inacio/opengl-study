//
//  Mesh.hpp
//  opengl-study
//
//  Created by Victor Soares on 11/06/24.
//

#ifndef Mesh_hpp
#define Mesh_hpp

#include <array>
#include <vector>
#include "Vector3.hpp"
#include "Matrix4.hpp"
using namespace std;

class Mesh {
public:
    
    Mesh(vector<Vector3>&, vector<Vector3>&);
  
    vector<Vector3> vertices;
    vector<Vector3> normals;
    vector<int> indices;
    
    void setVertices(const vector<Vector3>&);
    void setNormals(const vector<Vector3>&);
    void setIndices(const vector<int>&);
    void printVertices() const;
    void printTransformedVertices(const Matrix4&) const;
private:
    
};

#endif /* Mesh_hpp */
