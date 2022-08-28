#pragma once
#include<string>
#include<unordered_map>
#include"glm/glm.hpp"

struct shaders {
	const std::string vertexShader =
		"#version 410 core"
		"\n"
		"   layout(location = 0) in vec4 position;\n"
		//"	layout(location = 1) in vec2 texCoord;\n "
		"\n"
		//"	out vec2 v_TexCoord;"
		"\n"
		"uniform mat4 u_MVP;"
		"\n"
		"void main()"
		"{"
		" gl_Position = u_MVP * position;\n"
		//"	v_TexCoord = texCoord;\n"
		"\n"
		"};";

	const std::string fragmentShader =
		"#version 410 core"
		"\n"
		"layout(location = 0) out vec4 color;\n"
		//"	in vec2 v_TexCoord;\n"
		"	uniform vec4 u_Color;\n"
		//"	uniform sampler2D u_Texture;"
		"\n"
		"void main()"
		"{"
		"\n"
		//"	vec4 texColor = texture(u_Texture,v_TexCoord);\n"
		"   color = u_Color;\n"
		"};";

	
};

class Shader {

public:
	shaders ss;
	unsigned int m_RendererID;
	std::unordered_map<std::string, int> m_UniformLocationCache;

	int result;

	Shader();
	~Shader();

	void unBind()const;
	void Bind()const;
	void setUniform1i(const std::string& name, int value);
	void setUniform1f(const std::string& name, float value);
	void setUniform4f(const std::string& name, float v0, float v1, float v2, float v3);
	void setUniformMat4f(const std::string& name, const glm::mat4& matrix);
private:
	unsigned int createShader(const std::string& vertexShader, const std::string& fragmentShader);
	unsigned int compileShader(unsigned int type, const std::string& source);

		
	//bool compileShader();
	 int getUniformLocation(const std::string& name);

};