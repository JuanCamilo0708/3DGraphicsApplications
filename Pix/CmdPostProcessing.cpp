#include "CmdPostProcessing.h"

#include "PostProcessing.h"
bool CmdPostProcessingBeginDraw::Execute(const std::vector<std::string>& params)
{
	PostProcessing::Get()->BeginDraw();
	return true;
}

bool CmdPostProcessingEndDraw::Execute(const std::vector<std::string>& params)
{
	PostProcessing::Get()->EndDraw();
	return true;
}


bool CmdPostProcessingSetEffectType::Execute(const std::vector<std::string>& params)
{
	if (params.size() < 1) {
		return false;
	}

	EffectType effecType = EffectType::None;
	if (params[0] == "none") { effecType = EffectType::None; }
	else if (params[0] == "monochrome") { effecType = EffectType::Monochrome; }
	else if (params[0] == "invert") { effecType = EffectType::Invert; }
	else if (params[0] == "mirror") { effecType = EffectType::Mirror; }
	else if (params[0] == "blur") { effecType = EffectType::Blur; }
	else if (params[0] == "colormaskr") { effecType = EffectType::ColorMaskR; }
	else if (params[0] == "colormaskb") { effecType = EffectType::ColorMaskB; }
	else if (params[0] == "colormaskg") { effecType = EffectType::ColorMaskG; }
	else if (params[0] == "sepia") { effecType = EffectType::Sepia; }
	else if (params[0] == "wave") { effecType = EffectType::Wave; }
	else if (params[0] == "chromaticAberration") { effecType = EffectType::ChromaticAberration; }
	else { return false; }
	PostProcessing::Get()->SetEffectType(effecType);
	return true;
}
