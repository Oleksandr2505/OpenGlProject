#pragma once
#include"Renderer.h"

class Texture {
private:
	unsigned int m_RendererID;
	 std::string& m_filePath;
	unsigned char* m_localBuffer;
	int m_Width, m_Height, m_BPP;
public:
	Texture(std::string path);
	~Texture();
	void Bind(unsigned int slot = 0)const;
	void UnBind()const;

	inline int getWidth()const { return m_Width; }
	inline int getHeight(){return m_Height;}
};