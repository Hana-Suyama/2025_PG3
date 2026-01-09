#include "Unit.h"
#include "Selector.h"
#include <Novice.h>

void Unit::Init(int idref, int x, int y)
{
	id = idref;
	mapX_ = x;
	mapY_ = y;
}

void Unit::Update()
{
}

void Unit::Draw()
{
	if (isSelected_) {
		Novice::DrawBox(mapX_ * 50 + 10, mapY_ * 50 + 10, 30, 30, 0, GREEN, kFillModeSolid);
	} else {
		Novice::DrawBox(mapX_ * 50 + 10, mapY_ * 50 + 10, 30, 30, 0, WHITE, kFillModeSolid);
	}
}

void Unit::Move(int x, int y)
{
	mapX_ += x;
	mapY_ += y;
}

void Unit::MoveEnd(Selector* selector)
{
	isSelected_ = false;
	selector->SetSelectedUnit(nullptr);
	selector->SetSelectMode(SELECTOR);
	selector->SetX(mapX_);
	selector->SetY(mapY_);
}
