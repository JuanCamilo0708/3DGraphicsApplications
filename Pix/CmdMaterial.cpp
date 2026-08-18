#include "CmdMaterial.h"
#include "VariableCache.h"
#include "MaterialManager.h"
bool CmdSetMaterialEmissive::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 3) {
		return false;
	}

	VariableCache* vc = VariableCache::Get();
	float r = vc->GetFloat(params[0]);
	float g = vc->GetFloat(params[1]);
	float b = vc->GetFloat(params[2]);
	MaterialManager::Get()->SetmaterialEmissive({ r,g,b,1.0f });
	return true;
}

bool CmdSetMaterialAmbient::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 3) {
		return false;
	}

	VariableCache* vc = VariableCache::Get();
	float r = vc->GetFloat(params[0]);
	float g = vc->GetFloat(params[1]);
	float b = vc->GetFloat(params[2]);
	MaterialManager::Get()->SetmaterialAmbient({ r,g,b,1.0f });
	return true;
}

bool CmdSetMaterialSpecular::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 3) {
		return false;
	}

	VariableCache* vc = VariableCache::Get();
	float r = vc->GetFloat(params[0]);
	float g = vc->GetFloat(params[1]);
	float b = vc->GetFloat(params[2]);
	MaterialManager::Get()->SetmaterialSpecular({ r,g,b,1.0f });
	return true;
}

bool CmdSetMaterialDiffuse::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 3) {
		return false;
	}

	VariableCache* vc = VariableCache::Get();
	float r = vc->GetFloat(params[0]);
	float g = vc->GetFloat(params[1]);
	float b = vc->GetFloat(params[2]);
	MaterialManager::Get()->SetmaterialDiffuse({ r,g,b,1.0f });
	return true;
}
bool CmdSetMaterialShininess::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1) {
		return false;
	}
	VariableCache* vc = VariableCache::Get();
	float shininess = vc->GetFloat(params[0]);
	MaterialManager::Get()->SetmaterialShininess(shininess);
	return true;
}

