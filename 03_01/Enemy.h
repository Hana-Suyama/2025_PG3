#pragma once
class Enemy
{
public:

	enum class Phase {
		kApproach,
		kShot,
		kLeave,
	};

public:
	void Approach();
	void Shot();
	void Leave();

	void Action();

	void SetPhase(Phase phase) { phase_ = phase; }
private:
	static void (Enemy::* enemyFuncTable[])();

	Phase phase_ = Phase::kApproach;
};

