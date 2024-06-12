//
//  Vector3.cpp
//  opengl-study
//
//  Created by Victor Soares on 11/06/24.
//

#include "Vector3.hpp"
#include <math.h>

Vector3::Vector3(float x, float y, float z): x(x), y(y), z(z) {}

Vector3::Vector3(Vector3 const &other): x(other.x), y(other.y), z(other.z) {}

float Vector3::magnitude() const {
    return sqrt(x * x + y * y + z * z);
}

float Vector3::sqrtMagnitude() const {
    return x * x + y * y + z * z;
}

Vector3 Vector3::normalized() const {
    float mag = magnitude();
    
    if (mag > 0) {
        Vector3 newVec(x / mag, y / mag, z / mag);
        
        return newVec;
    }
    
   
    return *this;
}

Vector3& Vector3::normalize() {
    
    float mag = magnitude();
    
    if (mag > 0) {
        x /= mag;
        y /= mag;
        z /= mag;
    }
    
    
    return *this;
}

Vector3& Vector3::operator*=(Vector3 other) {
    x *= other.x;
    y *= other.y;
    z *= other.z;
    
    return *this;
}

Vector3& Vector3::operator*=(float num) {
    x *= num;
    y *= num;
    z *= num;
    
    return *this;
}

Vector3 Vector3::operator*(Vector3 other) {
    Vector3 temp(*this);
    return (temp *= other);
}

Vector3 Vector3::operator*(float num) {
    Vector3 temp(*this);
    return (temp *= num);
}

Vector3& Vector3::operator+=(Vector3 other) {
    x += other.x;
    y += other.y;
    z += other.z;
    
    return *this;
}

Vector3 Vector3::operator+(Vector3 other) {
    Vector3 temp(*this);
    return (temp += other);
}

Vector3& Vector3::operator+=(float num) {
    x += num;
    y += num;
    z += num;
    
    return *this;
}

Vector3 Vector3::operator+(float num) {
    Vector3 temp(*this);
    
    return (temp += num);
}

Vector3& Vector3::operator-=(Vector3 other) {
    x -= other.x;
    y -= other.y;
    z -= other.z;
    
    return *this;
}

Vector3& Vector3::operator-=(float num) {
    x -= num;
    y -= num;
    z -= num;
    
    return *this;
}

Vector3& Vector3::operator/=(Vector3 other) {
    x /= other.x;
    y /= other.y;
    z /= other.z;
    
    return *this;
}

Vector3& Vector3::operator/=(float scalar) {
    x /= scalar;
    y /= scalar;
    z /= scalar;
    
    return *this;
}

Vector3 Vector3::operator-(Vector3 other) {
    Vector3 temp(*this);
    
    return (temp -= other);
}

Vector3 Vector3::operator-(float scalar) {
    Vector3 temp(*this);
    
    return (temp -= scalar);
}

Vector3 Vector3::operator/(Vector3 other) {
    Vector3 temp(*this);
    
    return (temp /= other);
}

Vector3 Vector3::operator/(float scalar) {
    Vector3 temp(*this);
    
    return (temp /= scalar);
}





