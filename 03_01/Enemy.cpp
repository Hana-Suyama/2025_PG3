#include "Enemy.h"
#include <stdio.h>

void Enemy::Approach()
{
	printf("接近\n");
}

void Enemy::Shot()
{
	printf("射撃\n");
}

void Enemy::Leave()
{
	printf("離脱\n");
}

void Enemy::Action()
{
	(this->*enemyFuncTable[static_cast<size_t>(phase_)])();
}

void (Enemy::* Enemy::enemyFuncTable[])() {
	&Enemy::Approach,
	&Enemy::Shot,
	&Enemy::Leave,
};
