#include "SelectorCommand.h"

SelectorMoveCommand::SelectorMoveCommand(Selector* selector, int x, int y)
{
	selector_ = selector;
	x_ = x;
	y_ = y;
}

void SelectorMoveCommand::Exec()
{
	selector_->Move(x_, y_);
}

SelectUnitCommand::SelectUnitCommand(Selector* selector)
{
	selector_ = selector;
}

void SelectUnitCommand::Exec()
{
	selector_->SelectUnit();
}
