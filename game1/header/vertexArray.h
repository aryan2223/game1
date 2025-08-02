#pragma once

#ifndef VERTEX_ARRAY_H
#define VERTEX_ARRAY_H



#include <glad/glad.h>
#include "vertexBuffer.h"


class vertexArray {

public:
	unsigned int ID;
	vertexArray();


	void LinkAttrib(vertexBuffer& VBO, unsigned int layout,unsigned int numComponent,GLenum type,GLsizeiptr strid ,void* offest  );
	void bind();
	void unbind();
	void Delete();

};












#endif