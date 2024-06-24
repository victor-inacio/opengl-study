#version 410 core

layout (location = 0) in vec3 aPos;
layout (location = 1) in vec3 normal;
layout (location = 2) in vec2 aTexCoord;

uniform mat4 modelMatrix;
uniform mat4 perspectiveMatrix;

out vec3 outNormal;
out vec4 color;
out vec2 TexCoord;

void main() {
    outNormal = normal;
    TexCoord = aTexCoord;
    color = vec4(normal, 1.0);
    mat4 MVP = perspectiveMatrix * modelMatrix;
    
    vec4 newPos = MVP * vec4(aPos, 1.0f);
    gl_Position = newPos;
}
