//
//  Matrix4.cpp
//  opengl-study
//
//  Created by Victor Soares on 12/06/24.
//

#include "Matrix4.hpp"
#include <math.h>
#include <iostream>

Matrix4::Matrix4() {
    
}

Matrix4::Matrix4(float m00, float m01, float m02, float m03, float m10, float m11, float m12, float m13, float m20, float m21, float m22, float m23, float m30, float m31, float m32, float m33) {
    
    m[0][0] = m00;
    m[0][1] = m01;
    m[0][2] = m02;
    m[0][3] = m03;
    
    m[1][0] = m10;
    m[1][1] = m11;
    m[1][2] = m12;
    m[1][3] = m13;
    
    m[2][0] = m20;
    m[2][1] = m21;
    m[2][2] = m22;
    m[2][3] = m23;
    
    m[3][0] = m30;
    m[3][1] = m31;
    m[3][2] = m32;
    m[3][3] = m33;
}

Matrix4::Matrix4(const Matrix4& matrix) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            m[i][j] = matrix[i][j];
        }
    }
}

void Matrix4::print() const{
    
    for (int i = 0; i < 4; i++) {
        std::cout << "[";
        for (int j = 0; j < 4; j++) {
            std::cout << m[i][j];
            if (j < 3) {
                std::cout << ", ";
            }
        }
        std::cout << "]" << std::endl;
    }
    
}

Matrix4 Matrix4::identity() {
    Matrix4 temp;
    
    for (int i = 0; i < temp.rows; i++) {
        for (int j = 0; j < temp.cols; j++) {
            if (i == j) {
                temp[i][j] = 1;
            }
        }
    }
    
    return temp;
}

Matrix4 Matrix4::rotateX(float radians) {
    
    Matrix4 temp = Matrix4::identity();
    
    temp[1][1] = cos(radians);
    temp[1][2] = -sin(radians);
    
    temp[2][1] = sin(radians);
    temp[2][2] = cos(radians);
    
    return temp;
}

Matrix4 Matrix4::rotateY(float radians) {
    
    Matrix4 temp = Matrix4::identity();
    
    temp[0][0] = cos(radians);
    temp[0][2] = sin(radians);
    
    temp[2][0] = -sin(radians);
    temp[2][2] = cos(radians);
    
    return temp;
}

Matrix4 Matrix4::rotateZ(float radians) {
    
    Matrix4 temp = Matrix4::identity();
    
    temp[0][0] = cos(radians);
    temp[0][1] = -sin(radians);
    
    temp[1][0] = sin(radians);
    temp[1][1] = cos(radians);
    
    return temp;
}

Matrix4 Matrix4::scale(const Vector3 & scale) {
    
    Matrix4 temp = Matrix4::identity();
    
    temp[0][0] = scale.x;
    temp[1][1] = scale.y;
    temp[2][2] = scale.z;
    
    return temp;
}

Matrix4 Matrix4::translate(const Vector3 & vector) {
    Matrix4 temp = Matrix4::identity();
    
    temp[0][3] = vector.x;
    temp[1][3] = vector.y;
    temp[2][3] = vector.z;
    
    return temp;
}

Matrix4 Matrix4::perspective(float fov, float aspectRatio, float zNear, float zFar) {
    
    Matrix4 temp = Matrix4::identity();
    
    float halfTan = tan(fov / 2.0f);
    
    temp[0][0] = 1 / (aspectRatio * halfTan);
    temp[1][1] = 1 / halfTan;
    
    temp[2][2] = (-zNear - zFar) / (zNear - zFar);
    
    temp[2][3] = (2 * zNear * zFar) / (zNear - zFar);
    
    temp[3][2] = 1.0f;
    temp[3][3] = 0.0f;
    
    return temp;
}

float* Matrix4::operator[](const unsigned int index) {
    return m[index];
}

const float* Matrix4::operator[](const unsigned int index) const{
    return m[index];
}

Matrix4 Matrix4::operator+(const Matrix4& other) const {
 
    Matrix4 temp(*this);
    
    return (temp += other);
    
}

Matrix4 Matrix4::operator+(float scalar) const{
    
    Matrix4 temp(*this);
    
    return (temp += scalar);
    
}

Matrix4 Matrix4::operator-(const Matrix4& other) const {
    
    Matrix4 temp(*this);
    
    return (temp -= other);
    
}

Matrix4 Matrix4::operator-(float scalar) const{
    
    Matrix4 temp(*this);
    
    return (temp -= scalar);
    
}

Matrix4 Matrix4::operator*(const Matrix4& other) const {
    
    Matrix4 temp(*this);
    
    return (temp *= other);
    
}

Matrix4 Matrix4::operator*(float scalar) const{
    
    Matrix4 temp(*this);
    
    return (temp *= scalar);
    
}

Vector3 Matrix4::operator*(const Vector3 & other) const {
    
    Vector3 vec(
                m[0][0] * other.x + m[0][1] * other.y + m[0][2] * other.z + m[0][3] * 1,
                m[1][0] * other.x + m[1][1] * other.y + m[1][2] * other.z + m[1][3] * 1,
                m[2][0] * other.x + m[2][1] * other.y + m[2][2] * other.z + m[2][3] * 1
                );
    
    return vec;
    
}

Matrix4& Matrix4::operator=(const Matrix4& other) {
    
    if (this == &other) {
        return *this;
    }
    
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            m[i][j] = other[i][j];
        }
    }
    
    return *this;
    
}

Matrix4& Matrix4::operator+=(Matrix4 other) {
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            m[i][j] += other[i][j];
        }
    }
    
    return *this;
}

Matrix4& Matrix4::operator+=(float scalar) {
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            m[i][j] += scalar;
        }
    }
    
    return *this;
}

Matrix4& Matrix4::operator-=(Matrix4 other) {
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            m[i][j] -= other[i][j];
        }
    }
    
    return *this;
}

Matrix4& Matrix4::operator-=(float scalar) {
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            m[i][j] -= scalar;
        }
    }
    
    return *this;
}

Matrix4& Matrix4::operator*=(Matrix4 other) {
    
    Matrix4 temp;
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            for (int k = 0; k < 4; k++) {
                temp[i][j] += (m[i][k] * other[k][j]);
            }
        }
    }
    
    *this = temp;
    
    return *this;
}

Matrix4& Matrix4::operator*=(float scalar) {
    
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            m[i][j] *= scalar;
        }
    }
    
    return *this;
}
