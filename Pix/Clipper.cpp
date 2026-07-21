#include "Clipper.h"
#include "Viewport.h"
Clipper* Clipper::Get() {
	static Clipper sInstance;
	return &sInstance;
}
Clipper::Clipper() {

}
void Clipper::OnNewFrame() {
	mIsClipping = false;
}

bool Clipper::ClipPoint(const Vertex& v)
{
	if (!mIsClipping) {
		return false;
	}
	Viewport* vp = Viewport::Get();
	float minX = vp->GetMinX();
	float maxX = vp->GetMaxX();
	float minY = vp->GetMinY();
	float maxY = vp->GetMaxY();

	return v.position.x < minX || v.position.x > maxX
		|| v.position.y < minY || v.position.y > maxY;
}

bool Clipper::ClipLine(Vertex& a, Vertex& b)
{
	if (mIsClipping) {
		return false;
	}

}

bool Clipper::IsClipping() const
{
	return false;
}

void Clipper::SetClipping(bool enable)
{
}
