#include "vertexArray.h"

vertexArray::vertexArray()
{

	glGenVertexArrays(1, &ID);


}

void vertexArray::LinkAttrib(vertexBuffer& VBO, unsigned int layout, unsigned int numComponent, GLenum type, GLsizeiptr strid, void* offest)
{
	VBO.bind();
	glVertexAttribPointer(layout, numComponent, type, GL_FALSE, strid, offest);
	glEnableVertexAttribArray(layout);


	VBO.unbind();

}

void vertexArray::bind()
{
	glBindVertexArray(ID);



}

void vertexArray::unbind()
{
	glBindVertexArray(0);

}

void vertexArray::Delete()
{
	glDeleteVertexArrays(1, &ID);

}
