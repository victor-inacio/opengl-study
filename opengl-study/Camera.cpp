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
