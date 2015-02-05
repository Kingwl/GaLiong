#pragma once
#include "Preprocess.h"
#include "Texture.h"
#include <utility>

_L_BEGIN
class _L_ TextureBuffer
{
public:
	TextureBuffer();
	TextureBuffer(unsigned char length);
	__declspec(property(get = _GetCurrent, put = _SetCurrent)) Texture *Current;
	Texture *_GetCurrent()
	{
		return current;
	}
	void _SetCurrent(Texture *source)
	{
		current = source;
	}
	virtual TextureBuffer *MoveNext()
	{
		unsigned char i = 0;
		return MoveNext(i);
	}
	void Append(Texture *source);
	~TextureBuffer();
	friend void TextureBuffer::Append(Texture *source);
private:
	bool available = false;
	unsigned char offset = 0;
	Texture *textures, *last, *current, *append;

	TextureBuffer *MoveNext(unsigned char &flag);
};
_L_END