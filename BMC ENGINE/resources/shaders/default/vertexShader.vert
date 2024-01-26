#version 330
layout (location = 0) in vec3 aPos;
uniform float zoom;
uniform float widthMultiplier;
uniform bool improvedRenderer;

void main() {
    gl_Position = vec4(zoom * aPos.x, zoom * aPos.y, zoom * aPos.z, 1.0);

    // improved renderer allows for better sizing instead of limiting to 16:9
    if(improvedRenderer){
        gl_Position = vec4(zoom * widthMultiplier * aPos.x, zoom * aPos.y, zoom * aPos.z, 1.0);
    }
}