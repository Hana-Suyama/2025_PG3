#include "UnitCommand.h"

UnitMoveCommand::UnitMoveCommand(Unit* unit, int x, int y)
{
	unit_ = unit;
	x_ = x;
	y_ = y;
}

void UnitMoveCommand::Exec()
{
	unit_->Move(x_, y_);
}

UnitMoveEndCommand::UnitMoveEndCommand(Unit* unit, Selector* selector)
{
	unit_ = unit;
	selector_ = selector;
}

void UnitMoveEndCommand::Exec()
{
	unit_->MoveEnd(selector_);
}
