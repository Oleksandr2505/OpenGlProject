#include"VAO.h"
#include"Renderer.h"
#include"vertexBufferLayout.h"

VAO::VAO()  { glCall(glGenVertexArrays(1, &m_RendererID)); }
VAO::~VAO() { glCall(glDeleteVertexArrays(1, &m_RendererID)); }


void VAO:: addBuffer(const VBO&vbo,const vertexBufferLayout& layout)
{
	Bind();
	vbo.Bind();

	const auto& elements = layout.getElements();
	unsigned int offSet = 0;
	for (unsigned int i = 0; i < elements.size(); i++)
	{
		const auto& element = elements[i];
	
		glCall(glEnableVertexAttribArray(i));
		//glCall(glVertexAttribPointer(0, element.count, element.type, element.mormalized ,layout.getStride(),
			//(const void*)offSet));
		glCall(glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, sizeof(float) * 2,0));

		offSet += element.count * vertexBufferElements::getSizeOfType(element.type);
	}

	
}

void VAO::Bind() const{
	glCall(glBindVertexArray(m_RendererID));

}

void VAO::unBind()const{

	glCall(glBindVertexArray(0));
}