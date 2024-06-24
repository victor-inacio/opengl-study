//
//  Transform.hpp
//  opengl-study
//
//  Created by Victor Soares on 24/06/24.
//

#ifndef Transform_hpp
#define Transform_hpp

#include <iostream>
#include "Vector3.hpp"

class Transform {
    
public:
    Vector3 position, rotation, scale;
    
    Transform();
    Transform(Vector3,Vector3,Vector3);
    
    
    
private:
    
};

#endif /* Transform_hpp */
