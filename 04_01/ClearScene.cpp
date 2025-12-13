#include "ClearScene.h"
#include <Novice.h>
#include <memory>
#include "SceneManager.h"
#include "TitleScene.h"

void ClearScene::Initialize()
{
}

void ClearScene::Update()
{
	if (Novice::CheckHitKey(DIK_SPACE)) {
		std::unique_ptr<BaseScene> titleScene;
		titleScene = std::make_unique<TitleScene>();
		sceneManager_->SetNextScene(move(titleScene));
	}
}

void ClearScene::Draw()
{
	Novice::ScreenPrintf(0, 0, "Clear");
	Novice::ScreenPrintf(0, 20, "Press Space");
}
