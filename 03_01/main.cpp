#include <stdio.h>
#include "Enemy.h"

int main(){

	Enemy* enemy;
	enemy = new Enemy();

	enemy->SetPhase(Enemy::Phase::kApproach);
	enemy->Action();

	enemy->SetPhase(Enemy::Phase::kShot);
	enemy->Action();

	enemy->SetPhase(Enemy::Phase::kLeave);
	enemy->Action();

	delete enemy;

	return 0;
}