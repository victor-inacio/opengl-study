//
//  Texture.hpp
//  opengl-study
//
//  Created by Victor Soares on 22/06/24.
//

#ifndef Texture_hpp
#define Texture_hpp

#include <iostream>
#define GL_SILENCE_DEPRECATION
#include "OpenGL/gl.h"
using namespace std;

class Texture {
public:
    
    Texture(const string&);
    ~Texture();
    
    void bind() const;
    void unbind() const;
    
private:
    GLuint id;
};

#endif /* Texture_hpp */
