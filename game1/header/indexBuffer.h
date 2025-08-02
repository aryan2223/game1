#pragma once
#ifndef INDEX_BUFFER_H
#define INDEX_BUFFER_H

#include <glad/glad.h>

class IndexBuffer {

public:
	unsigned int ID;
	IndexBuffer(unsigned int*indices ,unsigned int size);


	void Bind();
	void Unbind();
	void Delete();






};








#endif