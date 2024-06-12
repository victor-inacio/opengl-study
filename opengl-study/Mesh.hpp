//
//  Mesh.hpp
//  opengl-study
//
//  Created by Victor Soares on 11/06/24.
//

#ifndef Mesh_hpp
#define Mesh_hpp

#include <stdio.h>
#include <array>
#include "Vector3.hpp"
using namespace std;

class Mesh {
public:
    
    Mesh();
    ~Mesh();
    
    void setVertices(vector<Vector3>);
    void setIndices(vector<int>);
private:
    
};

#endif /* Mesh_hpp */
