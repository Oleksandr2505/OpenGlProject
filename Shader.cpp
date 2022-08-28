#pragma once

#include<string>
#include"Shader.h"
#include"Renderer.h"
using namespace std;




	Shader::Shader() :m_RendererID(0)
	{
		m_RendererID  = createShader(ss.vertexShader,ss.fragmentShader);//binding;
	}

	Shader::~Shader()
	{
		glCall(glDeleteProgram(m_RendererID));
	}
	unsigned int Shader::createShader(const string& vertexShader, const string& fragmentShader)
	{

		unsigned int program = glCreateProgram();
		//now we are going to to link those two files into one grogram like binding
		unsigned int vs = compileShader(GL_VERTEX_SHADER, vertexShader);
		unsigned int fs = compileShader(GL_FRAGMENT_SHADER, fragmentShader);
		//attach both shaders in one program
		glAttachShader(program, vs);
		glAttachShader(program, fs);
		glLinkProgram(program);
		glGetProgramiv(program, GL_LINK_STATUS, &result);
		glValidateProgram(program);

		glDeleteShader(vs);
		glDeleteShader(fs);

		return program;
	}
	 unsigned int Shader::compileShader(unsigned int type, const std::string& source)
	{

		unsigned int id = glCreateShader(type); //created a shader object, in parameter specifes the type of created shader
		const char* src = source.c_str();
		glShaderSource(id, 1, &src, nullptr);
		glCompileShader(id);


		glGetShaderiv(id, GL_COMPILE_STATUS, &result);

		if (result == GL_FALSE)
		{
			int length;
			glGetShaderiv(id, GL_INFO_LOG_LENGTH, &length);
			char message[512];
			glGetShaderInfoLog(id, 512, &length, message);
			cout << "Failed to compile" << (type == GL_VERTEX_SHADER ? "vertex" : "fragment") << "shader!" << endl;
			cout << message << endl;
			glDeleteShader(id);
			return 0;

		}

		return id;
	}

	 

	
	
	void Shader::Bind()const
	{
		
		glCall(glUseProgram(m_RendererID));
	}

	void Shader::unBind()const
	{
		glCall(glUseProgram(0));
	}

	void Shader::setUniform1i(const std::string& name, int value)
	{
		glCall(glUniform1i(getUniformLocation(name), value));
	}

	void Shader::setUniform1f(const std::string& name, float value)
	{
		glCall(glUniform1f(getUniformLocation(name), value));
	}


	void Shader::setUniform4f(const std::string& name, float v0, float v1, float v2, float v3)
	{
		glCall(glUniform4f(getUniformLocation(name), v0,v1,v2,v3));
	}

	void Shader::setUniformMat4f(const std::string& name, const glm::mat4& matrix)
	{
		glCall(glUniformMatrix4fv(getUniformLocation(name),1,GL_FALSE,&matrix[0][0]));
	}

	 int Shader::getUniformLocation(const std::string& name)
	{
		if (m_UniformLocationCache.find(name) != m_UniformLocationCache.end())
			return m_UniformLocationCache[name];

		glCall( int location = glGetUniformLocation(m_RendererID, name.c_str()));
		if (location == -1)
			std::cout << "Warning uniform " << name << "doesnt exist " << std::endl;

		 m_UniformLocationCache[name] = location;
		return location;

	}

