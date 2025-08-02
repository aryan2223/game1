#include <iostream>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

#include "ShaderClass.h"	
#include "vertexArray.h"
#include "vertexBuffer.h"
#include "indexBuffer.h"

#include "shape.h"	
#include "vector"


int main() {


	glfwInit();

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);


	GLFWwindow* window = glfwCreateWindow(800, 800, "OpenGL Window", NULL, NULL);
	if (window == NULL) {
		std::cout << "Failed to create GLFW window" << std::endl;
		glfwTerminate();
		return -1; 

	}

	glfwMakeContextCurrent(window);

	std::vector<Shape*> shapes;

	GLfloat triangle1[] = {
		// pos          // color
		-0.5f, -0.5f,    0.8f, 0.1f, 0.1f,
		 0.0f,  0.5f,    0.1f, 0.8f, 0.1f,
		 0.5f, -0.5f,    0.1f, 0.1f, 0.8f
	};
	unsigned int indices1[] = { 0, 1, 2 };

	GLfloat triangle2[] = {
		-0.8f,  0.7f,    0.3f, 0.9f, 0.3f,
		-0.3f,  0.7f,    0.9f, 0.3f, 0.3f,
		-0.55f, 0.2f,    0.3f, 0.3f, 0.9f
	};
	unsigned int indices2[] = { 0, 1, 2 };

	gladLoadGL();
	glViewport(0, 0, 800, 800);

	Shader shaderProgram("res/shader/vertex.shader", "res/shader/fragment.shader");

	
	shapes.push_back(new Shape(triangle1, sizeof(triangle1), indices1, sizeof(indices1), shaderProgram));
	shapes.push_back(new Shape(triangle2, sizeof(triangle2), indices2, sizeof(indices2), shaderProgram));


	glClearColor(0.07f,0.13f,0.17f,1.0f);

	glClear(GL_COLOR_BUFFER_BIT);

	glfwSwapBuffers(window);



	while (!glfwWindowShouldClose(window))
	{






		glClearColor(0.07f, 0.13f, 0.17f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		for (Shape* shape : shapes)
			shape->Draw(shaderProgram);


		//glDrawElements(GL_TRIANGLES, 9, GL_UNSIGNED_INT, 0);
		glfwSwapBuffers(window);

		 


		glfwPollEvents();


	}

	for (Shape* shape : shapes) {
		shape->Delete();
		delete shape;
	}
	shaderProgram.Delete();
	glfwDestroyWindow(window);

	glfwTerminate();
	return 0;	
}