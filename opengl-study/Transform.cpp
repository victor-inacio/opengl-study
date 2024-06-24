//
//  Transform.cpp
//  opengl-study
//
//  Created by Victor Soares on 24/06/24.
//

#include "Transform.hpp"

Transform::Transform():
    position(0, 0, 0),
    rotation(0, 0, 0),
    scale(1, 1, 1) {}

Transform::Transform(Vector3 position, Vector3 rotation, Vector3 scale): position(position), rotation(rotation), scale(scale) {}
