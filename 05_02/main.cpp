#include <Novice.h>
#include <memory>
#include "InputHandler.h"
#include "Cube.h"

const char kWindowTitle[] = "LE2A_10_スヤマハナ_05_02_確認課題";

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	std::unique_ptr<InputHandler> inputHandler = std::make_unique<InputHandler>();
	inputHandler->AssignMoveUpCommand2PressKeyW();
	inputHandler->AssignMoveLeftCommand2PressKeyA();
	inputHandler->AssignMoveDownCommand2PressKeyS();
	inputHandler->AssignMoveRightCommand2PressKeyD();
	inputHandler->Initialize(keys, preKeys);

	ICommand* iCommand = nullptr;
	std::unique_ptr<Cube> cube = std::make_unique<Cube>();

	cube->Initialize();

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		iCommand = inputHandler->HandleInput();

		if (iCommand) {
			iCommand->Exec(*cube);
		}

		cube->Update();

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		cube->Draw();

		for (int i = 0; i < 30; i++) {
			Novice::DrawLine(0, i * 50, 1280, i * 50, BLACK);
			Novice::DrawLine(i * 50, 0, i * 50, 720, BLACK);
		}

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
