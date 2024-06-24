#version 410 core

in vec4 color;
in vec3 outNormal;
in vec2 TexCoord;

out vec4 FragColor;

uniform sampler2D myTexture;

void main() {
    FragColor = texture(myTexture, TexCoord);
}
