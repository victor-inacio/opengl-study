#version 410 core

layout (location = 0) in vec3 aPos;

uniform mat4 modelMatrix;
uniform mat4 perspectiveMatrix;

void main() {

    mat4 MVP = perspectiveMatrix * modelMatrix;
    
    vec4 newPos = MVP * vec4(aPos, 1.0f);
    gl_Position = newPos;
}
