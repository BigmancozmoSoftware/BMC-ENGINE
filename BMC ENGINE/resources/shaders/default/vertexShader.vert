#version 330
layout (location = 0) in vec3 aPos;
uniform float zoom;
uniform float widthMultiplier;

void main() {
    gl_Position = vec4(zoom * widthMultiplier * aPos.x, zoom * aPos.y, zoom * aPos.z, 1.0);
}