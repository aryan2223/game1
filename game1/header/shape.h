#pragma once
#ifndef SHAPE_H
#define SHAPE_H


#include <glad/glad.h>
#include "vertexBuffer.h"	
#include "vertexArray.h"
#include "indexBuffer.h"
#include "ShaderClass.h"

class Shape {
	
public:
	vertexArray VAO;
	vertexBuffer* VBO;
	IndexBuffer* IBO;
	unsigned int IndexCount;
	

	Shape(GLfloat* vertices, size_t vSize, unsigned int* indices, size_t iSize, Shader& shader, int posSize = 2, int stride = 5) {
	
		IndexCount = iSize / sizeof(unsigned int);
		VAO.bind();
		VBO = new vertexBuffer(vertices, vSize);
		IBO = new IndexBuffer(indices, iSize);	
		VAO.LinkAttrib(*VBO, 0, posSize, GL_FLOAT, stride * sizeof(float), (void*)0);
		VAO.LinkAttrib(*VBO, 1, 3, GL_FLOAT, stride * sizeof(float), (void*)(posSize * sizeof(float)));
	
		VAO.unbind();
		VBO->unbind();
		IBO->Unbind();
	
	}
	void Draw(Shader& shader) {
		shader.Activate();
		VAO.bind();
		glDrawElements(GL_TRIANGLES, IndexCount, GL_UNSIGNED_INT,0);
	
	}
	void Delete() {
		VAO.Delete();
		VBO->Delete();
		IBO->Delete();
		delete VBO;
		delete IBO;
	}

};









#endif