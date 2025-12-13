#pragma once
#include "BaseScene.h"

class StageScene : public BaseScene
{
public:

	void Initialize() override;

	void Update() override;

	void Draw() override;

private:

	int x = 640;
	int y = 360;

	int enemyX = 640;
	int enemyY = 100;

	int bulletX = 0;
	int bulletY = 0;
	bool isShot = false;

};

