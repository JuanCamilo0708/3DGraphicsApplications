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
			"BeginDraw(Topology)\n"
			"\n"
			"- starts storing vertices\n"
			"- topology (point, line, triangle)";
	}
	bool Execute(const std::vector<std::string>& params) override;

private:

};
