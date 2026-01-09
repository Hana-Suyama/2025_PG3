#pragma once

class Selector;

class Unit
{
private:
	int mapX_ = 0;
	int mapY_ = 0;
	int mapSize_ = 32;
	int id = 0;
	bool isSelected_ = false;

public:
	Unit() = default;
	void Init(int idref, int x, int y);
	void Update();
	void Draw();

	void Move(int x, int y);
	void MoveEnd(Selector* selector);

	int GetX() { return mapX_; }
	int GetY() { return mapY_; }

	void SetIsSelected(bool isSelected) { isSelected_ = isSelected; }

	void SetX(int x) { mapX_ = x; }
	void SetY(int y) { mapY_ = y; }
};

