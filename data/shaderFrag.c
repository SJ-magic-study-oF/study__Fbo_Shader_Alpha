#version 120
#extension GL_ARB_texture_rectangle : enable
#extension GL_EXT_gpu_shader4 : enable

uniform sampler2DRect texture0;

void main(){
	vec4 color = gl_Color;
	// color.a = 0.5;
	color.g = color.a;
	
	gl_FragColor = color;
}
