#include "ShaderClass.h"

std::string get_File_Contents(const char* filename)
{

	std::ifstream in(filename, std::ios::binary);
	if (in)
	{
		std::string contents;
		in.seekg(0, std::ios::end);
		contents.resize(in.tellg());
		in.seekg(0, std::ios::beg);
		in.read(&contents[0], contents.size());
		in.close();
		return(contents);
	}
	throw(errno);
}

Shader::Shader(const char* vertexFile, const char* fragmentFile) {

	std::string vertexCode = get_File_Contents(vertexFile);
	std::string fragmentCode = get_File_Contents(fragmentFile);	
	const char* vertexSource = vertexCode.c_str();
	const char* fragmentSource = fragmentCode.c_str();

	unsigned int VertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(VertexShader, 1, &vertexSource, NULL);
	glCompileShader(VertexShader);

	unsigned int FragmenetShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(FragmenetShader, 1, &fragmentSource, NULL);
	glCompileShader(FragmenetShader);

ID = glCreateProgram();
	glAttachShader(ID, VertexShader);
	glAttachShader(ID, FragmenetShader);
	glLinkProgram(ID);


	glDeleteShader(VertexShader);
	glDeleteShader(FragmenetShader);
}

void Shader::Activate()
{
	glUseProgram(ID);	


}

void Shader::Delete()
{

	glDeleteProgram(ID);
}
