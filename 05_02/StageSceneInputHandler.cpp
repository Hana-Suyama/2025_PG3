#include "StageSceneInputHandler.h"
#include <Novice.h>
#include "SelectorCommand.h"
#include "UnitCommand.h"

StageSceneInputHandler::StageSceneInputHandler(Selector* selector)
{

	selector_ = selector;

	selectorW_ = std::make_unique<SelectorMoveCommand>(selector, 0, -1);
	selectorA_ = std::make_unique<SelectorMoveCommand>(selector, -1, 0);
	selectorS_ = std::make_unique<SelectorMoveCommand>(selector, 0, 1);
	selectorD_ = std::make_unique<SelectorMoveCommand>(selector, 1, 0);
	selectorSpace_ = std::make_unique<SelectUnitCommand>(selector);

	unitW_ = std::make_unique<UnitMoveCommand>(nullptr, 0, -1);
	unitA_ = std::make_unique<UnitMoveCommand>(nullptr, -1, 0);
	unitS_ = std::make_unique<UnitMoveCommand>(nullptr, 0, 1);
	unitD_ = std::make_unique<UnitMoveCommand>(nullptr, 1, 0);
	unitSpace_ = std::make_unique<UnitMoveEndCommand>(nullptr, selector_);
}

void StageSceneInputHandler::UpdateKeyState()
{
	// キー入力を受け取る
	memcpy(preKeys_, keys_, 256);
	Novice::GetHitKeyStateAll(keys_);
}

IStageSceneCommand* StageSceneInputHandler::SelectorHandleInput(Selector* selector, Unit* unit)
{
	if (unit != nullptr) {
		if ((preKeys_[DIK_SPACE] == 0 && keys_[DIK_SPACE] != 0)) {
			selector->SetUnit(unit);
			unit->SetIsSelected(true);
			return selectorSpace_.get();
		}
	}

	if ((preKeys_[DIK_W] == 0 && keys_[DIK_W] != 0)) {
		return selectorW_.get();
	}
	if (preKeys_[DIK_A] == 0 && keys_[DIK_A] != 0) {
		return selectorA_.get();
	}
	if (preKeys_[DIK_S] == 0 && keys_[DIK_S] != 0) {
		return selectorS_.get();
	}
	if (preKeys_[DIK_D] == 0 && keys_[DIK_D] != 0) {
		return selectorD_.get();
	}

	return nullptr;
}

IStageSceneCommand* StageSceneInputHandler::UnitHandleInput(Unit* unit)
{

	if ((preKeys_[DIK_SPACE] == 0 && keys_[DIK_SPACE] != 0)) {
		unitSpace_.reset();
		unitSpace_ = std::make_unique<UnitMoveEndCommand>(unit, selector_);
		return unitSpace_.get();
	}

	if ((preKeys_[DIK_W] == 0 && keys_[DIK_W] != 0)) {
		unitW_.reset();
		unitW_ = std::make_unique<UnitMoveCommand>(unit, 0, -1);
		return unitW_.get();
	}
	if (preKeys_[DIK_A] == 0 && keys_[DIK_A] != 0) {
		unitA_.reset();
		unitA_ = std::make_unique<UnitMoveCommand>(unit, -1, 0);
		return unitA_.get();
	}
	if (preKeys_[DIK_S] == 0 && keys_[DIK_S] != 0) {
		unitS_.reset();
		unitS_ = std::make_unique<UnitMoveCommand>(unit, 0, 1);
		return unitS_.get();
	}
	if (preKeys_[DIK_D] == 0 && keys_[DIK_D] != 0) {
		unitD_.reset();
		unitD_ = std::make_unique<UnitMoveCommand>(unit, 1, 0);
		return unitD_.get();
	}

	return nullptr;
}
