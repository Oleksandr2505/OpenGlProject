#pragma once

class IBO{
private:
	unsigned int m_RendererID;
	unsigned int m_Count;
public:
	IBO(const unsigned* data, unsigned int count);
	~IBO();
	void Bind()const;
	void unBind()const;

	inline unsigned int GetCount() const { return m_Count; }
};