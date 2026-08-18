#pragma once

#include "Command.h"


class CmdSetMaterialEmissive : public Command{
public:
	const char* GetName() override {
		return "SetMaterialEmissive";
	}
	const char* GetDescription() override {
		return
			"SetMaterialEmissive(r, g, b)\n"
			"- sets the rgb values for the material emissive color";
	}
	bool Execute(const std::vector<std::string>& params) override;
};

class CmdSetMaterialAmbient : public Command {
public:
	const char* GetName() override {
		return "SetMateriaAmbient";
	}
	const char* GetDescription() override {
		return
			"SetMateriaAmbient(r, g, b)\n"
			"- sets the rgb values for the material ambient color";
	}
	bool Execute(const std::vector<std::string>& params) override;
};
class CmdSetMaterialDiffuse : public Command {
public:
	const char* GetName() override {
		return "SetMaterialDiffuse";
	}
	const char* GetDescription() override {
		return
			"SetMaterialDiffuse(r, g, b)\n"
			"- sets the rgb values for the material diffuse color";
	}
	bool Execute(const std::vector<std::string>& params) override;
};
class CmdSetMaterialSpecular : public Command {
public:
	const char* GetName() override {
		return "SetMateriaSpecular";
	}
	const char* GetDescription() override {
		return
			"SetMateriaSpecular(r, g, b)\n"
			"- sets the rgb values for the material specular color";
	}
	bool Execute(const std::vector<std::string>& params) override;
};
class CmdSetMaterialShininess : public Command {
public:
	const char* GetName() override {
		return "SetMateriaShininess";
	}
	const char* GetDescription() override {
		return
			"SetMateriaShininess(float)\n"
			"- sets material shininess value";
	}
	bool Execute(const std::vector<std::string>& params) override;
};