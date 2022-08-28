#include"VBO.h"
#include"Renderer.h"



    VBO::VBO(const void* data, unsigned int size) {
        //bind the vertex array object first, then bind and set vertex buffer's, an dthen configure vertex attributes
        glGenBuffers(1, &m_RendererID);
        glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
        glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);//here we bound our buffer
    }
    VBO :: ~VBO() {
        glCall(glDeleteBuffers(1, &m_RendererID));
    }
    void VBO:: Bind()const {
        glBindBuffer(GL_ARRAY_BUFFER, m_RendererID);
    }
    void VBO::unBind() const{
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }