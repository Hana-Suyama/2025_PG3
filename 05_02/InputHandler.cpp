#include "InputHandler.h"
#include <Novice.h>

void InputHandler::AssignMoveUpCommand2PressKeyW()
{
	std::unique_ptr<ICommand> command = std::make_unique<MoveUpCommand>();
	pressKeyW_ = move(command);
}

void InputHandler::AssignMoveLeftCommand2PressKeyA()
{
	std::unique_ptr<ICommand> command = std::make_unique<MoveLeftCommand>();
	pressKeyA_ = move(command);
}

void InputHandler::AssignMoveDownCommand2PressKeyS()
{
	std::unique_ptr<ICommand> command = std::make_unique<MoveDownCommand>();
	pressKeyS_ = move(command);
}

void InputHandler::AssignMoveRightCommand2PressKeyD()
{
	std::unique_ptr<ICommand> command = std::make_unique<MoveRightCommand>();
	pressKeyD_ = move(command);
}

void InputHandler::Initialize(char* keys, char* prekeys)
{
	keys_ = keys;
	preKeys_ = prekeys;
}

ICommand* InputHandler::HandleInput() {
	if (Novice::CheckHitKey(DIK_W)) {
		return pressKeyW_.get();
	}
	if (Novice::CheckHitKey(DIK_A)) {
		return pressKeyA_.get();
	}
	if (Novice::CheckHitKey(DIK_S)) {
		return pressKeyS_.get();
	}
	if (Novice::CheckHitKey(DIK_D)) {
		return pressKeyD_.get();
	}

	return nullptr;
}