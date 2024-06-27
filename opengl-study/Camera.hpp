//
//  Camera.hpp
//  opengl-study
//
//  Created by Victor Soares on 16/06/24.
//

#ifndef Camera_hpp
#define Camera_hpp

#include "Matrix4.hpp"
#include "Transform.hpp"
class Camera {
    
public:
    float fov, zNear, zFar;
    Camera(float,float,float);
    
    Transform transform = Transform();
    
    Matrix4 perspectiveMatrix() const;
    Matrix4 viewMatrix() const;
    
private:
    
};

#endif /* Camera_hpp */
