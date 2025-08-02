#pragma once
#ifndef SHADER_CLASS_H
#define SHADER_CLASS_H


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <cerrno>

std::string get_File_Contents(const char* filename);

class Shader {

public:
	unsigned int ID;
	Shader(const char* vertexFile, const char* fragmentFile);

	void Activate();
	void Delete();





	




};
















#endif