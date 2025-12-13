#include "TitleScene.h"
#include <Novice.h>
#include <memory>
#include "StageScene.h"
#include "SceneManager.h"

void TitleScene::Initialize()
{
}

void TitleScene::Update()
{
	if (Novice::CheckHitKey(DIK_RETURN)) {
		std::unique_ptr<BaseScene> stageScene;
		stageScene = std::make_unique<StageScene>();
		sceneManager_->SetNextScene(move(stageScene));
	}
}

void TitleScene::Draw()
{
	Novice::ScreenPrintf(0, 0, "Title");
	Novice::ScreenPrintf(0, 20, "Press Enter");
}
