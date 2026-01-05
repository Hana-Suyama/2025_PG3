#pragma once
class Cube
{
public:

	void Initialize();
	void Update();
	void Draw();

	void MoveRight();
	void MoveLeft();
	void MoveUp();
	void MoveDown();

private:

	int posX;
	int posY;

};

