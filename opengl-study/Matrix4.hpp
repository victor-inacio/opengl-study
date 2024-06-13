//
//  Matrix4.hpp
//  opengl-study
//
//  Created by Victor Soares on 12/06/24.
//

#ifndef Matrix4_hpp
#define Matrix4_hpp

#include "Vector3.hpp"

class Matrix4 {

public:
    Matrix4();
    Matrix4(float, float, float, float, float, float, float, float, float, float, float, float, float, float, float, float);
    Matrix4(const Matrix4&)
    
    static Matrix4 identity();
    static Matrix4 rotateX(float);
    static Matrix4 rotateY(float);
    static Matrix4 rotateZ(float);
    
    Matrix4& operator=(const Matrix4&);
    
    const float* operator[](const unsigned int) const;
    
    float* operator[](const unsigned int);
    
    Matrix4 operator+(const Matrix4&) const;
    Matrix4 operator+(float) const;
    Matrix4 operator-(const Matrix4&) const;
    Matrix4 operator-(float) const;
    Matrix4 operator*(const Matrix4&) const;
    Matrix4 operator*(float) const;
    Vector3 operator*(const Vector3&) const;
    
    Matrix4& operator+=(Matrix4);
    Matrix4& operator+=(float);
    Matrix4& operator-=(Matrix4);
    Matrix4& operator-=(float);
    Matrix4& operator*=(Matrix4);
    Matrix4& operator*=(float);
    Matrix4& operator*=(Vector3);
    
    
private:
    int cols = 4;
    int rows = 4;
    float m[4][4] = {
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
    };
};

#endif /* Matrix4_hpp */
