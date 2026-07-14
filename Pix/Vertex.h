#pragma once
#include "MathHelper.h"
#include <XColors.h>



struct Vertex
{
	Vector3 position;
	X::Color color;
};

inline Vector3 LerpPosition(const Vector3& a, const Vector3& b, float t) {
	return{
		a.x + (b.x - a.x) * t,
		a.y + (b.y - a.y) * t,
		a.z + (b.z - a.z) * t,
	};

}

inline X::Color LerpColor(const X::Color& a, const X::Color& b, float t) {

	return{
		a.r + (b.r - a.r) * t,
		a.g + (b.g - a.g) * t,
		a.b + (b.b - a.b) * t,
		a.a + (b.a - a.a) * t
	};
}

inline Vertex LerpVertex(const Vertex& a, const Vertex& b, float t) {
	Vertex v;
	v.position = LerpPosition(a.position, b.position, t);
	v.color = LerpColor(a.color, b.color, t);

	v.position.x = floorf(v.position.x + 0.5f);
	v.position.y = floorf(v.position.y + 0.5f);

	return v;
}