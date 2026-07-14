#include "Rasterizer.h"

Rasterizer* Rasterizer::Get()
{
	static Rasterizer sInstance;
	return &sInstance;
}
void DrawLineHorizontal(const Vertex& left, const Vertex& right) {
	float dx = right.position.x - left.position.x;
	int startX = static_cast<int>(left.position.x);
	int endX = static_cast<int>(right.position.x);
	for (int x = startX; x <= endX; ++x) {
		float t = static_cast<float>(x - startX) / dx;
		Vertex v = LerpVertex(left, right, t);
		Rasterizer::Get()->DrawPoint(v);
	}
}
void DrawLineVertical(const Vertex& low, const Vertex& high) {
	float dy = high.position.y - low.position.y;
	int startY = static_cast<int>(low.position.y);
	int endY = static_cast<int>(high.position.y);
	for (int y = startY; y <= endY; ++y) {
		float t = static_cast<float>(y - startY) / dy;
		Vertex v = LerpVertex(low, high, t);
		Rasterizer::Get()->DrawPoint(v);
	}
}
void Rasterizer::SetColor(X::Color color)
{
	mColor = color;
}

void Rasterizer::SetFillMode(FillMode fillMode)
{
	mFillMode = fillMode;
}

void Rasterizer::DrawPoint(int x, int y)
{
	X::DrawPixel(x, y, mColor);
}

void Rasterizer::DrawPoint(const Vertex& v)
{
	X::DrawPixel(v.position.x, v.position.y, v.color);
}

void Rasterizer::DrawLine(const Vertex& a, const Vertex& b)
{
	float dx = b.position.x - a.position.x;
	float dy = b.position.y - a.position.y;

	if (MathHelper::CheckEqual(dx, 0.0f) || abs(dy / dx) > 1.0f) {
		if (a.position.y < b.position.y) {
			DrawLineVertical(a, b);
		}
		else
		{
			DrawLineVertical(b, a);
		}
	}
	else {
		if (a.position.x < b.position.x) {
			DrawLineHorizontal(a, b);
			
		}
		else
		{
			DrawLineHorizontal(b, a);
		}
	}
}

void Rasterizer::DrawTriangle(const Vertex& a, const Vertex& b, const Vertex& c)
{
	switch (mFillMode)
	{	
	case FillMode::Wireframe:
		DrawLine(a, b);
		DrawLine(b, c);
		DrawLine(c, a);
		break;
	case FillMode::Solid: {
		std::vector<Vertex> sortedVertices = { a,b,c };
		std::sort(sortedVertices.begin(), sortedVertices.end(),
			[](const Vertex& lhs, const Vertex& rhs) {
				return lhs.position.y < rhs.position.y;
			});
		DrawFilledTriangle(sortedVertices[0], sortedVertices[1], sortedVertices[2]);
	}
		
		break;
	default:
		break;
	}
}

void Rasterizer::DrawFilledTriangle(const Vertex& a, const Vertex& b, const Vertex& c)
{
	float dy = c.position.y - a.position.y;
	if (MathHelper::CheckEqual(a.position.y, b.position.y))
	{
		int startY = static_cast<int>(a.position.y);
		int endY = static_cast<int>(c.position.y);
		for (int y = startY; y <= endY; ++y) {
			float t = static_cast<float>(y - startY) / dy;
			Vertex aSide = LerpVertex(a, c, t);
			Vertex bSide = LerpVertex(b, c, t);
			DrawLine(aSide, bSide);
		}

	}
	else if (MathHelper::CheckEqual(b.position.y, c.position.y)) {
		int startY = static_cast<int>(a.position.y);
		int endY = static_cast<int>(c.position.y);
		for (int y = startY; y <= endY; ++y) {
			float t = static_cast<float>(y - startY) / dy;
			Vertex bSide = LerpVertex(a, b, t);
			Vertex cSide = LerpVertex(a, c, t);
			DrawLine(bSide, cSide);
		}
	}
	else {
		float t = (b.position.y - a.position.y)/dy;
		Vertex splitVertex = LerpVertex(a, c, t);
		DrawFilledTriangle(a, b, splitVertex);
		DrawFilledTriangle(b,splitVertex,c);

	}
}
