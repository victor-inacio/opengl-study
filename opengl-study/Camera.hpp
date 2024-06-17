//
//  Camera.hpp
//  opengl-study
//
//  Created by Victor Soares on 16/06/24.
//

#ifndef Camera_hpp
#define Camera_hpp

#include "Matrix4.hpp"

class Camera {
    
public:
    float fov, zNear, zFar;
    Camera(float,float,float);
    
    Matrix4 perspectiveMatrix() const;
    
private:
    
};

#endif /* Camera_hpp */
