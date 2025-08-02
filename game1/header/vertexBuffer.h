#pragma once

#ifndef VERTEX_BUFFER_H
#define VERTEX_BUFFER_H

#include <glad/glad.h>
#include <GLFW/glfw3.h>



class vertexBuffer {


public:
	unsigned int ID;
	vertexBuffer(float* vertices, unsigned int size);
	
	void bind();
	void unbind();
	void Delete();
			


};















#endif

