#include "Clipper.h"
#include "Viewport.h"

const short BIT_INSIDE = 0;	 // 0000
const short BIT_LEFT = 1 << 0;// 0001
const short BIT_RIGHT = 1 << 1;// 0010
const short BIT_BOTTOM = 1 << 2;// 0100
const short BIT_TOP = 1 << 3;// 1000

// generate a bit code that signifies where the point is
// if code is not 0, it is outside of the screen in one of the 8 regions 
// compare code with other point's code to confirm if the line cresses screen 
short GetOutputCode(float x, float y) {
	Viewport* vp = Viewport::Get();
	short code = BIT_INSIDE;
	if (x < vp->GetMinX()) {
		code |= BIT_LEFT;
	}
	else if (x > vp->GetMaxX()) {
		code |= BIT_RIGHT;
	}
	if (y < vp->GetMinY()) {
		code |= BIT_TOP;
	}
	else if (y > vp->GetMaxY()) {
		code |= BIT_BOTTOM;
	}

	return code;
}

//Triangle Clipper
enum ClipEdge {
	CE_LEFT,
	CE_TOP,
	CE_RIGHT,
	CE_BOTTOM,
	CE_COUNT
};

bool IsInFront(ClipEdge edge, const Vector3& pos) {
	Viewport* vp = Viewport::Get();
	switch (edge)
	{
	case CE_LEFT:
		return pos.x > vp->GetMinX();
	case CE_TOP:
		return pos.y > vp->GetMinY();
	case CE_RIGHT:
		return pos.x < vp->GetMaxX();
	case CE_BOTTOM:
		return pos.y < vp->GetMaxY();
	default:
		break;
	}
	return false;
}
Vertex ComputeIntersection(ClipEdge edge, const Vertex& a, const Vertex& b) {
	Viewport* vp = Viewport::Get();
	float t = 0.0f;
	switch (edge)
	{
	case CE_LEFT:
		t = (vp->GetMinX() - a.position.x) / (b.position.x - a.position.x); break;
	case CE_TOP:
		t = (vp->GetMinY() - a.position.y) / (b.position.y - a.position.y); break;
	case CE_RIGHT:
		t = (vp->GetMaxX() - a.position.x) / (b.position.x - a.position.x); break;
	case CE_BOTTOM:
		t = (vp->GetMaxY() - a.position.y) / (b.position.y - a.position.y); break;
	default:
		break;
	}
	return LerpVertex(a, b, t);
}
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
	if (!mIsClipping) {
		return false;
	}

	Viewport* vp = Viewport::Get();
	float minX = vp->GetMinX();
	float maxX = vp->GetMaxX();
	float minY = vp->GetMinY();
	float maxY = vp->GetMaxY();

	//
	short codeA = GetOutputCode(a.position.x, a.position.y);
	short codeB = GetOutputCode(b.position.x, b.position.y);
	while (true)
	{
		if (!(codeA | codeB)) {
			//both are 0000, so both are in the viewport
			break;
		}
		else if (codeA & codeB)
		{
			// both are along the same edge, so they will never cross the viewport
			break;
		}
		float t = 0.0f;
		short outCode = codeB > codeA ? codeB : codeA;
		if (outCode & BIT_TOP) { t = (minY - a.position.y) / (b.position.y - a.position.y); }
		else if (outCode & BIT_BOTTOM) { t = (maxY - a.position.y) / (b.position.y - a.position.y); }
		else if (outCode & BIT_LEFT) { t = (minX - a.position.x) / (b.position.x - a.position.x); }
		else if (outCode & BIT_RIGHT) { t = (maxX - a.position.x) / (b.position.x - a.position.x); }

		if (outCode == codeA) {
			a = LerpVertex(a, b, t);
			codeA = GetOutputCode(a.position.x, a.position.y);

		}
		else {
			b = LerpVertex(a, b, t);
			codeB = GetOutputCode(b.position.x, b.position.y);
		}
	}
	return (codeA | codeB);
}

bool Clipper::ClipTriangle(std::vector<Vertex>& v)
{
	if (!mIsClipping) {
		return false;
	}

	std::vector<Vertex> newVertices;
	for (int i = 0; i < CE_COUNT; ++i) {
		newVertices.clear();
		ClipEdge edge = (ClipEdge)i;
		for (size_t n = 0; n < v.size(); ++n) {

			//nPO = n plus one
			size_t nPO = (n + 1) % v.size();
			//current Vertex
			const Vertex& vN = v[n];
			// next Vertex 
			const Vertex& vNPO = v[nPO];

			//which points are inside and which are outside
			bool nIsInFront = IsInFront(edge, vN.position);
			bool nPOIsInFront = IsInFront(edge, vNPO.position);

			//case 1 both in front
			if (nIsInFront && nPOIsInFront) {
				newVertices.push_back(vNPO);
			}
			//case 2 both behind
			else if (!nIsInFront && !nPOIsInFront) {

			}
			//case 3 n in front, nPO behind
			else if (nIsInFront && !nPOIsInFront) {
				newVertices.push_back(ComputeIntersection(edge, vN, vNPO));
			}
			//case 3 n behind, nPO front
			else if (!nIsInFront && nPOIsInFront) {

				newVertices.push_back(ComputeIntersection(edge, vN, vNPO));
				newVertices.push_back(vNPO);
			}

		}
		v = newVertices;
	}
	return newVertices.empty();
}

bool Clipper::IsClipping() const
{
	return mIsClipping;
}

void Clipper::SetClipping(bool enable)
{
	mIsClipping = enable;
}
