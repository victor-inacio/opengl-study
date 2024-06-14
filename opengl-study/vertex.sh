#version 410 core

layout (location = 0) in vec3 aPos;

uniform mat4 transform;

void main() {
    vec4 transformedVec = transform * vec4(aPos.xyz, 1.0);
    
    gl_Position = transformedVec;
}
