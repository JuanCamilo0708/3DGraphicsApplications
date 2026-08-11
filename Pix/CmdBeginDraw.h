#pragma once
#include "Command.h"
class CmdBeginDraw: public Command
{
public:
	const char* GetName() override
	{
		return "BeginDraw";
	}
	const char* GetDescription() override {
		return
			"BeginDraw(Topology, <applyTransform>)\n"
			"\n"
			"- starts storing vertices\n"
			"- topology (point, line, triangle)"
			"- (optional) apply transfprm to apply 3d pipeline transformation to vertices";
	}
	bool Execute(const std::vector<std::string>& params) override;

private:

};
