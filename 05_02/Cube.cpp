#include "Cube.h"
#include <Novice.h>

void Cube::Initialize()
{
}

void Cube::Update()
{
}

void Cube::Draw()
{
	Novice::DrawBox((posX * 50) + 10, (posY * 50) + 10, 30, 30, 0, WHITE, kFillModeSolid);
}

void Cube::MoveRight()
{
	posX++;
}

void Cube::MoveLeft()
{
	posX--;
}

void Cube::MoveUp()
{
	posY--;
}

void Cube::MoveDown()
{
	posY++;
}
