#version 410 core

layout (location = 0) in vec3 aPos;

uniform mat4 transform;


void main() {
    vec4 newPos = transform * vec4(aPos, 1.0f);
    gl_Position = newPos;
}
