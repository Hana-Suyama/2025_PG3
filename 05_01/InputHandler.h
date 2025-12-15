#pragma once
#include "Command.h"
#include <memory>

class InputHandler
{
public:
	ICommand* HandleInput();

	void AssignMoveLeftCommand2PressKeyA();
	void AssignMoveRightCommand2PressKeyD();

private:

	std::unique_ptr<ICommand> pressKeyD_;
	std::unique_ptr<ICommand> pressKeyA_;

};

