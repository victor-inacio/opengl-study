//
//  Vector3.hpp
//  opengl-study
//
//  Created by Victor Soares on 11/06/24.
//

#ifndef Vector3_hpp
#define Vector3_hpp

class Vector3 {
public:
    float x, y, z;
    
    Vector3(float,float,float);
    Vector3(const Vector3&);
 
    void print() const;
    
    float magnitude() const;
    float sqrtMagnitude() const;
    Vector3 normalized() const;
    Vector3& normalize();
    static float angle(const Vector3&, const Vector3&);
    static Vector3 cross(const Vector3&, const Vector3&);
    
    Vector3 operator+(Vector3);
    Vector3 operator+(float);
    Vector3 operator*(Vector3);
    Vector3 operator*(float);
    Vector3 operator-(Vector3);
    Vector3 operator-(float);
    Vector3 operator/(Vector3);
    Vector3 operator/(float);
    
    Vector3& operator+=(Vector3);
    Vector3& operator+=(float);
    Vector3& operator*=(Vector3);
    Vector3& operator*=(float);
    Vector3& operator-=(Vector3);
    Vector3& operator-=(float);
    Vector3& operator/=(Vector3);
    Vector3& operator/=(float);
private:
    
};

#endif /* Vector3_hpp */
