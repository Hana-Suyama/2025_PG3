#pragma once
#include "Command.h"
#include <memory>

class InputHandler
{
public:
	ICommand* HandleInput();

	void AssignMoveUpCommand2PressKeyW();
	void AssignMoveLeftCommand2PressKeyA();
	void AssignMoveDownCommand2PressKeyS();
	void AssignMoveRightCommand2PressKeyD();

	void Initialize(char* keys, char* prekeys);

private:

	std::unique_ptr<ICommand> pressKeyW_;
	std::unique_ptr<ICommand> pressKeyA_;
	std::unique_ptr<ICommand> pressKeyS_;
	std::unique_ptr<ICommand> pressKeyD_;

	// キー入力結果を受け取る箱
	char* keys_;
	char* preKeys_;

};

