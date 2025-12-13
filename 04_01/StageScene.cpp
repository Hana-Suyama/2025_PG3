#include "StageScene.h"
#include <Novice.h>
#include <memory>
#include "SceneManager.h"
#include "ClearScene.h"

void StageScene::Initialize()
{
}

void StageScene::Update()
{

	if (Novice::CheckHitKey(DIK_RIGHTARROW)) {
		x++;
	}
	if (Novice::CheckHitKey(DIK_LEFTARROW)) {
		x--;
	}
	if (Novice::CheckHitKey(DIK_UPARROW)) {
		y--;
	}
	if (Novice::CheckHitKey(DIK_DOWNARROW)) {
		y++;
	}

	if (Novice::CheckHitKey(DIK_SPACE) && !isShot) {
		bulletX = x;
		bulletY = y;
		isShot = true;
	}

	if (bulletY < 0) {
		isShot = false;
	}

	if (isShot) {
		bulletY -= 3;
	}

	float a = static_cast<float>(enemyX - bulletX);
	float b = static_cast<float>(enemyY - bulletY);
	float d = sqrtf(a * a + b * b);

	if (d <= 80) {
		std::unique_ptr<BaseScene> clearScene;
		clearScene = std::make_unique<ClearScene>();
		sceneManager_->SetNextScene(move(clearScene));
	}

}

void StageScene::Draw()
{
	Novice::ScreenPrintf(0, 0, "Stage");
	Novice::ScreenPrintf(0, 20, "Arrow : Move");
	Novice::ScreenPrintf(0, 40, "Space : Shot");

	Novice::DrawEllipse(x, y, 50, 50, 0, WHITE, kFillModeSolid);
	Novice::DrawEllipse(enemyX, enemyY, 50, 50, 0, RED, kFillModeSolid);
	if (isShot) {
		Novice::DrawEllipse(bulletX, bulletY, 30, 30, 0, BLUE, kFillModeSolid);
	}
}
