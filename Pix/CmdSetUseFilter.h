#pragma once

#include "Command.h"

class CmdSetUseFilter : public Command {
public:
	const char* GetName() override {
		return "SetUseFilter";
	}
	const char* GetDescription() override {
		return
			"SetUseFilter(enable)\n"
			"\n"
			"-enable/disables using bilinear filter on textures";

	}
	bool Execute(const std::vector<std::string>& params) override;
};