#version 330 core
layout (location = 0) in vec3 aPos;
layout(location = 1) in vec3 color;

out vec4 vColor;
  
uniform mat4 transform;

void main()
{
    gl_Position = transform * vec4(aPos, 1.0f);
    vColor = vec4(color, 1.0f);
} 