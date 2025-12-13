#include "SceneManager.h"

void SceneManager::Update()
{

	if (nextScene_ != nullptr) {
		currentScene_.reset();
		currentScene_ = move(nextScene_);
		currentScene_->Initialize();
		currentScene_->SetSceneManager(this);
		nextScene_.reset();
		nextScene_ = nullptr;
	}

	currentScene_->Update();

}

void SceneManager::Draw()
{

	currentScene_->Draw();

}
