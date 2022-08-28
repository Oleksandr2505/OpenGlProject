#pragma once
#include<GL/glew.h>
#include"Shader.h"
#include"VAO.h"
#include"IBO.h"
#include<iostream>

#define ASSERT(x) if(!(x)) __debugbreak();
#define glCall(x) glClearError();\
    x;\
    ASSERT(glLockCall(#x, __FILE__, __LINE__))

void glClearError();
bool glLockCall(const char* function, const char* file, int line);

class Renderer {
public:
    void Clear(float r);
   void Draw( const IBO& ibo, const VAO& vao, const Shader& shader)const;

};