#pragma once

#include <GL/glew.h>

#include <string>
#include <unordered_map>

class Shader
{
private:
	std::string m_FilePath;
	unsigned int m_RendererID;
	std::unordered_map < std::string, int > m_UniformLocationCache;

	int GetUniformLocation(const std::string& name);
	std::string ParseShader(const std::string& filepath);
	unsigned int CreateShader(const std::string& vertexShader, const std::string& fragShader);
	unsigned int CompileShader(unsigned int type, const std::string& source);
public:
	Shader(const std::string& vertexShader, const std::string& fragShader);
	~Shader();

	void Bind() const;
	void Unbind() const;

	void setUniform1i(const std::string& name, int value);
	void setUniform4f(const std::string& name, float f1, float f2, float f3, float f4);
	void setUniform3f(const std::string& name, float f1, float f2, float f3);

};