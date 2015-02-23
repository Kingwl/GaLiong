#pragma once
#include "Preprocess.h"
#include "Texture.h"
#include "TextureBase.h"

_L_BEGIN
class _L_ TextureBuffer : public TextureBase
{
public:
	TextureBuffer();
	TextureBuffer(unsigned char length);
	void Append(Texture *source);
	virtual const bool IsAvailable() override final
	{
		return current->IsAvailable();
	}
	virtual const bool IsInformative() override final
	{
		return current->IsInformative();
	}
	virtual void Generate()override final
	{
		current->Generate();
	}
	virtual Texture &Get() override final
	{
		return *current;
	}
	virtual const Buffer GetData() override final
	{
		return current->GetData();
	}
	virtual const TextureID GetIndex() override final
	{
		return current->GetIndex();
	}
	virtual const unsigned char GetPixelLength() override final
	{
		return current->GetPixelLength();
	}
	virtual const Size GetSize() override final
	{
		return current->GetSize();
	}
	TextureBuffer &MoveFor(unsigned char steps);
	TextureBuffer &MoveNext()
	{
		return MoveFor(1);
	}
	virtual const bool SameType(PixelFormat pixelFormat, ByteSize byteSize) override final
	{
		return current->SameType(pixelFormat, byteSize);
	}
	void Set(Texture *source)
	{
		current = source;
	}
	virtual void Set(BufferLength dataLength, Buffer data, Size size, PixelFormat pixelFormat, ByteSize byteSize) override final
	{
		current->Set(dataLength, data, size, pixelFormat, byteSize);
	}
	~TextureBuffer();
private:
	bool available = false;
	bool informative = false;
	unsigned char max = 0;
	Texture *textures = nullptr, *last = nullptr, *current = nullptr, *append = nullptr;
};
_L_END
