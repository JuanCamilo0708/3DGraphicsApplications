#include "CmdVertex.h"
#include "PrimitivesManager.h"
bool CmdVertex::Execute(const std::vector<std::string>& params)
{
	float x = 0.0f, y = 0.0f, z = 0.0f;
	float r = 0.0f, g = 0.0f, b = 1.0f;
	if (params.size() == 2) {
		x = std::stof(params[0]);
		y = std::stof(params[1]);
	}
	else if (params.size() == 3) {
		x = std::stof(params[0]);
		y = std::stof(params[1]);
		z = std::stof(params[2]);
	}
	else if (params.size() == 5) {
		x = std::stof(params[0]);
		y = std::stof(params[1]);
		r = std::stof(params[2]);
		g = std::stof(params[3]);
		b = std::stof(params[4]);
	}
	else if (params.size() == 6) {
		x = std::stof(params[0]);
		y = std::stof(params[1]);
		z = std::stof(params[2]);
		r = std::stof(params[3]);
		g = std::stof(params[4]);
		b = std::stof(params[5]);
	}
	else {
		return false;
	}

	Vertex v;
	v.position = { x,y,z };
	v.color = { r,g,b,1.0f };
	PrimitivesManager::Get()->AddVertex(v);
	return true;
}
