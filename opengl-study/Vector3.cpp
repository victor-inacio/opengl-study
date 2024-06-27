
#include "Vector3.hpp"
#include <math.h>
#include <iostream>

Vector3::Vector3(float x, float y, float z): x(x), y(y), z(z) {}

Vector3::Vector3(Vector3 const &other): x(other.x), y(other.y), z(other.z) {}

static float angle(const Vector3& vec1, const Vector3& vec2) {
    
    return acos((vec1.x * vec2.x + vec1.y * vec2.y + vec1.z * vec2.z) / (vec1.magnitude() * vec2.magnitude()));
    
}

static Vector3 cross(const Vector3& vec1, const Vector3& vec2) {
    return Vector3(
                   vec1.y * vec2.z - vec1.z * vec2.y,
                   vec1.z * vec2.x - vec1.x * vec2.z,
                   vec1.x * vec2.y - vec1.y * vec2.x
                   );
}

void Vector3::print() const {
    std::cout << "(";
    
    std::cout << x;
    std::cout << ", ";
    
    std::cout << y;
    std::cout << ", ";
    
    std::cout << z;
    std::cout << ")" << std::endl;
}

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

Vector3 Vector3::operator-() {
    return Vector3(-x, -y, -z);
}

Vector3 Vector3::operator-() const {
    return Vector3(-x, -y, -z);
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





