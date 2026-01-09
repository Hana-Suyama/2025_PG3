#pragma once
#include "Unit.h"

enum {
	SELECTOR,
	UNIT,
};

class Selector
{
private:
	int mapX_;
	int mapY_;
	int mapSize_;

	int startX = 0;
	int startY = 0;

	int selectMode_;

	Unit* unit_;
	Unit* selectedUnit_;

public:
	Selector();

	void Init();
	void Update();
	void Draw();

	void Move(int x, int y);

	void SelectUnit();

	void StartSet();

	int GetSelectMode() { return selectMode_; }
	Unit* GetSelectedUnitAddress() { return selectedUnit_; }
	void SetUnit(Unit* unit) { unit_ = unit; }
	void SetSelectedUnit(Unit* unit) { selectedUnit_ = unit; }

	int GetX() { return mapX_; }
	int GetY() { return mapY_; }

	void SetSelectMode(int selectMode) { selectMode_ = selectMode; }
	void SetX(int x) { mapX_ = x; }
	void SetY(int y) { mapY_ = y; }

};

