#include "CmdModel.h"
#include "ModelManager.h"
#include "PrimitivesManager.h"
bool CmdModel::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1) {
		return false;
	}

	const Model* model = ModelManager::Get()->GetModel(params[0]);
	for (uint32_t i = 0; i < model->GetVertexCount(); ++i) {
		PrimitivesManager::Get()->AddVertex(model->GetVertex(i));
	}
	return true;
}
