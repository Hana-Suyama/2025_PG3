#pragma once
class Player
{
public:

	void Initialize();
	void Update();
	void Draw();

	void MoveRight();
	void MoveLeft();

private:

	int posX = 100;
	int posY = 100;
	int speed = 2;

};

