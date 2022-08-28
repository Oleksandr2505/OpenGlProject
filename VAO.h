#pragma once
#include"VBO.h"
//#include"Renderer.h"
//#include"vertexBufferLayout.h"
class vertexBufferLayout;
class VAO {
	unsigned int m_RendererID;
	//unsigned int m_Stride;
public:
	VAO();
	~VAO();
	void addBuffer(const VBO& vbo,const vertexBufferLayout& layout);
	void Bind()const;
	void unBind()const;
};