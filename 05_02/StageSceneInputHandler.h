#pragma once
#include <memory>
#include "IStageSceneCommand.h"
#include "Selector.h"

class StageSceneInputHandler
{
private:

	char keys_[256] = { 0 };
	char preKeys_[256] = { 0 };

	Selector* selector_;
	Unit* selectedUnit_;

	std::unique_ptr<IStageSceneCommand> selectorW_;
	std::unique_ptr<IStageSceneCommand> selectorA_;
	std::unique_ptr<IStageSceneCommand> selectorS_;
	std::unique_ptr<IStageSceneCommand> selectorD_;
	std::unique_ptr<IStageSceneCommand> selectorSpace_;

	std::unique_ptr<IStageSceneCommand> unitW_;
	std::unique_ptr<IStageSceneCommand> unitA_;
	std::unique_ptr<IStageSceneCommand> unitS_;
	std::unique_ptr<IStageSceneCommand> unitD_;
	std::unique_ptr<IStageSceneCommand> unitSpace_;

public:

	StageSceneInputHandler(Selector* selector);
	void UpdateKeyState();

	IStageSceneCommand* SelectorHandleInput(Selector* selector, Unit* unit);
	IStageSceneCommand* UnitHandleInput(Unit* unit);

	bool CheckUndoStatus();

};

