#include "InputHandler.h"
#include <Novice.h>

ICommand* InputHandler::HandleInput()
{
	if (Novice::CheckHitKey(DIK_D)) {
		return pressKeyD_.get();
	}

	if (Novice::CheckHitKey(DIK_A)) {
		return pressKeyA_.get();
	}

	return nullptr;
}

void InputHandler::AssignMoveLeftCommand2PressKeyA()
{
	std::unique_ptr<ICommand> command = std::make_unique<MoveLeftCommand>();
	pressKeyA_ = move(command);
}

void InputHandler::AssignMoveRightCommand2PressKeyD()
{
	std::unique_ptr<ICommand> command = std::make_unique<MoveRightCommand>();
	pressKeyD_ = move(command);
}
