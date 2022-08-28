//#include"IBO.h"
#include"Renderer.h"



IBO::IBO(const unsigned* data, unsigned int count)
   : m_Count(count) 
{
    ASSERT(sizeof(unsigned int) == sizeof(GLuint));

    glCall(glGenBuffers(1, &m_RendererID));
    glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID);
    glBufferData(GL_ELEMENT_ARRAY_BUFFER, count*sizeof(unsigned int), data, GL_STATIC_DRAW);//push data into (VBO) buffer object
}
IBO::~IBO () {

    glCall(glDeleteBuffers(1, &m_RendererID));
}

void IBO::Bind() const{

    glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_RendererID));
}

void IBO::unBind()const {

    glCall(glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0));
}