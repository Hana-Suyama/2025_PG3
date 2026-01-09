#include "Selector.h"
#include <Novice.h>

Selector::Selector()
{
	mapSize_ = 30;
	mapX_ = 0;
	mapY_ = 0;

	selectMode_ = SELECTOR;

	unit_ = nullptr;
	selectedUnit_ = nullptr;

}

void Selector::Init()
{
	
}

void Selector::Update()
{

}

void Selector::Draw()
{
	if (selectMode_ == SELECTOR) {
		Novice::DrawBox(mapX_ * 50, mapY_ * 50, 50, 50, 0, RED, kFillModeWireFrame);
	}
}

void Selector::Move(int x, int y)
{
	mapX_ += x;
	mapY_ += y;
}

void Selector::SelectUnit()
{
	selectMode_ = UNIT;
	selectedUnit_ = unit_;

	startX = mapX_;
	startY = mapY_;
}

void Selector::StartSet()
{
	mapX_ = startX;
	mapY_ = startY;
	selectedUnit_->SetX(startX);
	selectedUnit_->SetY(startY);
}
