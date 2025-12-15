#include "Player.h"
#include <Novice.h>

void Player::Initialize()
{
}

void Player::Update()
{
}

void Player::Draw()
{
	Novice::DrawBox(posX, posY, 20, 20, 0, WHITE, kFillModeSolid);
}

void Player::MoveRight()
{
	posX += speed;
}

void Player::MoveLeft()
{
	posX -= speed;
}
