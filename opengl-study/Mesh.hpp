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
    
    Mesh(vector<Vector3>&, vector<int>&);
  
    vector<Vector3> vertices;
    vector<int> indices;
    
    void setVertices(vector<Vector3>&);
    void setIndices(vector<int>&);
    void printVertices() const;
    void printTransformedVertices(const Matrix4&) const;
private:
    
};

#endif /* Mesh_hpp */
