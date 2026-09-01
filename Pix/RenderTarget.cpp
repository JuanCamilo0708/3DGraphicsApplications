#include "RenderTarget.h"
void RenderTarget::Initialize(int width, int height, const X::Color& clearColor)
{
	if (width != mWidth || height != mheight) 
	{
		mWidth = width;
		mheight = height;
		mRenderPixels.reset();
		mRenderPixels = std::make_unique < X::Color[]>(width * height);

		ClearImage(clearColor);
	}
}

void RenderTarget::ClearImage(const X::Color& clearColor)
{
	for (int h = 0; h < mheight; h++)
	{
		for (int w = 0; w < mWidth; w++)
		{
			const int index = w + (h * mWidth);
			mRenderPixels[index] = clearColor;
		}
	}
}
void RenderTarget::DrawPixel(int x, int y, X::Color& color) 
{
	if (x >= 0 && x < mWidth && y >= 0 && y < mheight)
	{
		const int index = x + (y * mWidth);
		mRenderPixels[index] = color;
	}
}
const X::Color& RenderTarget::GetColor(int x, int y) const
{
	x = std::clamp(x, 0, mWidth - 1);
	y = std::clamp(y, 0, mheight - 1);
}

int RenderTarget::GetWidth() const
{
	return 0;
}
int RenderTarget::Getheight() const
{
	return 0;
}
