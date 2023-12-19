#version 330
layout (location = 0) in vec3 aPos;
uniform float zoom;

void main() {
    gl_Position = vec4(zoom * aPos.x, zoom * aPos.y, zoom * aPos.z, 1.0);
}