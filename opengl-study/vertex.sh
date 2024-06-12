#version 410 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec4 color;

out vec4 aColor;

void main() {
    gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0f);
    aColor = color;
}
