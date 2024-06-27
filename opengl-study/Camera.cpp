//
//  Camera.cpp
//  opengl-study
//
//  Created by Victor Soares on 16/06/24.
//

#include "Camera.hpp"

Camera::Camera(float fov, float zNear, float zFar): fov(fov), zNear(zNear), zFar(zFar) {}

Matrix4 Camera::perspectiveMatrix() const {
    return Matrix4::perspective(fov, 1.0, zNear, zFar);
}

Matrix4 Camera::viewMatrix() const {
    Matrix4 translate = Matrix4::translate(-transform.position);
    
    Matrix4 rotX = Matrix4::rotateX(-transform.rotation.x);
    Matrix4 rotY = Matrix4::rotateY(-transform.rotation.y);
    Matrix4 rotZ = Matrix4::rotateZ(-transform.rotation.z);
    
    Matrix4 rotation = rotX * rotY * rotZ;
    
    return translate * rotation;
}
