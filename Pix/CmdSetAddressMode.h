#pragma once


#include "Command.h"

class CmdSetAddressMode : public Command {
public:
	const char* GetName() override {
		return "SetAddressMode";
	}
	const char* GetDescription() override {
		return
			"SetAddressMode(addressMode)\n"
			"\n"
			"- sets address mode for uv\n"
			"- <border> sets a color if outside of 0-1\n"
			"- <clamp> mantain edge color if outside of 0-1\n"
			"- <wrap> repeat uv color  if outside of 0-1\n"
			"- <mirror> flips and reapeats uv color if outside of 0-1\n";

	}
	bool Execute(const std::vector<std::string>& params) override;
};