#include "Graphics.h"

#include "Viewport.h"
#include "Clipper.h"
void Graphics::NewFrame()
{
	Viewport::Get()->OnNewFrame();
	Clipper::Get()->OnNewFrame();
	Matrix4 matTrans = Matrix4::Translation(4.0, 10.0, 5.0);
	Matrix4 matRotX = Matrix4::RotationX(45 * MathHelper::DegToRad);
	Matrix4 matRotY = Matrix4::RotationX(15 * MathHelper::DegToRad);
	Matrix4 matFinal = matRotX * matRotY * matTrans;
	Matrix4 matInv = MathHelper::Inverse(matFinal);
	Matrix4 matIden = matFinal * matInv;
	int hi = 0;
	if (MathHelper::CheckEqual(matIden._11, 1.0f)) {
		++hi;
	}
	if (MathHelper::CheckEqual(matIden._12, 0.0f)) {
		++hi;

	}
	if (MathHelper::CheckEqual(matIden._13, 0.0f)) {
		++hi;

	}
	if (MathHelper::CheckEqual(matIden._14, 0.0f)) {
		++hi;

	}
	if (MathHelper::CheckEqual(matIden._21, 0.0f)) {
		++hi;

	}
	if (MathHelper::CheckEqual(matIden._22, 1.0f)) {
		++hi;

	}
	if (MathHelper::CheckEqual(matIden._23, 0.0f)) {
		++hi;

	}
	if (MathHelper::CheckEqual(matIden._24, 0.0f)) {
		++hi;

	}
	if (MathHelper::CheckEqual(matIden._31, 0.0f)) {
		++hi;

	}
	if (MathHelper::CheckEqual(matIden._32, 0.0f)) {
		++hi;

	}
	if (MathHelper::CheckEqual(matIden._33, 1.0f)) {
		++hi;

	}
	if (MathHelper::CheckEqual(matIden._34, 0.0f)) {
		++hi;

	}
	if (MathHelper::CheckEqual(matIden._41, 0.0f)) {
		++hi;

	}
	if (MathHelper::CheckEqual(matIden._42, 0.0f)) {
		++hi;

	}
	if (MathHelper::CheckEqual(matIden._43, 0.0f)) {
		++hi;

	}
	if (MathHelper::CheckEqual(matIden._44, 1.0f)) {
		++hi;

	}
}