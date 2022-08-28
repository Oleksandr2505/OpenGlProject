#include"Renderer.h"
#include<iostream>

void glClearError() {
    while (glGetError() != GL_NO_ERROR);
}

bool glLockCall(const char* function, const char* file, int line)
{
    while (GLenum error = glGetError()) {
    std::cout << "[openGL] (" << error << ") " << function << " : " << file << line << std::endl;
        return false;
    }
    return true;
}
void Renderer:: Clear(float r) { 
    glClearColor(0.8f, 0.4f, 0.4f, 2.0f); 
    glClear(GL_COLOR_BUFFER_BIT); }

void Renderer::Draw(  const IBO& ibo, const VAO& vao, const Shader& s)const{
    s.Bind();
   
   vao.Bind();
    ibo.Bind();
   glCall(glDrawElements(GL_TRIANGLES, ibo.GetCount(), GL_UNSIGNED_INT, nullptr));
}