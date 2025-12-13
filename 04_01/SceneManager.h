#pragma once
#include <memory>
#include "BaseScene.h"

class SceneManager
{
public:

	void Update();

	void Draw();

	void SetNextScene(std::unique_ptr<BaseScene> nextScene) { nextScene_ = move(nextScene); };

private:

	std::unique_ptr<BaseScene> nextScene_ = nullptr;
	std::unique_ptr<BaseScene> currentScene_ = nullptr;

};

