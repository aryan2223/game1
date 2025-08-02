#include "vertexBuffer.h"

vertexBuffer::vertexBuffer(float* vertices, unsigned int size)
{
	glGenBuffers(1, &ID);
	glBindBuffer(GL_ARRAY_BUFFER, ID);
	glBufferData(GL_ARRAY_BUFFER, size, vertices, GL_STATIC_DRAW);
}

void vertexBuffer::bind()
{
	glBindBuffer(GL_ARRAY_BUFFER, ID);

}

void vertexBuffer::unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);

}

void vertexBuffer::Delete()
{
	glDeleteBuffers(1, &ID);
}
