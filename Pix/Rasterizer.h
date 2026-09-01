#pragma once

#include <XEngine.h>
#include "Vertex.h"
enum class FillMode {
	Wireframe,
	Solid
};
enum class ShadeMode {
	Flat,
	Gouraud,
	Phong
};
class Rasterizer
{
public:
	static Rasterizer* Get();

public:
	void SetColor(X::Color color);
	void SetFillMode(FillMode fillMode);
	void SetShadeMode(ShadeMode shadeMode);
	ShadeMode GetShadeMode();

	void DrawPoint(int x, int y);
	
	void DrawPoint(const Vertex& v);
	void DrawLine(const Vertex& a, const Vertex& b);
	void DrawTriangle(const Vertex& a, const Vertex& b, const Vertex& c);
	void DrawFilledTriangle(const Vertex& a, const Vertex& b, const Vertex& c);
private:

	X::Color mColor = X::Colors::White;
	FillMode mFillMode = FillMode::Solid;
	ShadeMode mShadeMode = ShadeMode::Phong;
};