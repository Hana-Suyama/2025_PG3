#include <Novice.h>
#include <memory>
#include "StageSceneInputHandler.h"
#include "IStageSceneCommand.h"
#include "Selector.h"
#include <list>

const char kWindowTitle[] = "LE2A_10_スヤマハナ_05_02_確認課題";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	char keys_[256] = { 0 };
	char preKeys_[256] = { 0 };

	IStageSceneCommand* iCommand = nullptr;
	std::list<IStageSceneCommand*> commandHistory_;
	std::list<IStageSceneCommand*>::iterator commandHistoryItr_;

	std::unique_ptr<Selector> selector = std::make_unique<Selector>();
	selector->Init();

	std::unique_ptr<StageSceneInputHandler> inputHandler = std::make_unique<StageSceneInputHandler>(selector.get());

	std::list<std::unique_ptr<Unit>> units;
	for (int i = 0; i < 4; i++) {
		std::unique_ptr<Unit> unit = std::make_unique<Unit>();
		unit->Init(i, 2 * i, 2 * i);
		units.push_back(move(unit));
	}

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys_, keys_, 256);
		Novice::GetHitKeyStateAll(keys_);

		///
		/// ↓更新処理ここから
		///

		inputHandler->UpdateKeyState();

		Unit* selectUnit = nullptr;
		for (auto& unit : units) {
			if (unit->GetX() == selector->GetX() && unit->GetY() == selector->GetY()) {
				selectUnit = unit.get();
			}
		}

		if (selector->GetSelectMode() == SELECTOR) {
			iCommand = inputHandler->SelectorHandleInput(selector.get(), selectUnit);
			if (iCommand) {
				iCommand->Exec();
			}
		} else if (selector->GetSelectMode() == UNIT) {

			if ((preKeys_[DIK_Z] == 0 && keys_[DIK_Z] != 0) && (keys_[DIK_LCONTROL])) {
				if (!commandHistory_.empty()) {
					commandHistory_.pop_back();
				}
			}

			iCommand = inputHandler->UnitHandleInput(selector->GetSelectedUnitAddress());

			if (iCommand) {
				commandHistory_.push_back(iCommand);
			}
			
			selector->StartSet();
			for(int i = 0; i < commandHistory_.size(); i++){
				iCommand = *std::next(commandHistory_.begin(), i);
				if (iCommand) {
					iCommand->Exec();
				}
			}
		}

		if (iCommand) {
			if (selector->GetSelectMode() != UNIT) {
				commandHistory_.clear();
			}
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		for (int i = 0; i < 30; i++) {
			Novice::DrawLine(0, i * 50, 1280, i * 50, BLACK);
			Novice::DrawLine(i * 50, 0, i * 50, 720, BLACK);
		}

		for (auto& unit : units) {
			unit->Draw();
		}

		selector->Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		/*if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}*/
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
