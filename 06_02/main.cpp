#include <Novice.h>
#include <vector>
#include <string>
#include <fstream>
#include <cassert>
#include <iostream>
#include <sstream>
#include <thread>
#include <mutex>

const char kWindowTitle[] = "LE2A_10_スヤマハナ_06_02_確認課題";

void LoadMapChipCsv(const std::string& filePath, std::vector<std::vector<int>>* mapchip) {
	
	//ファイルを開く
	std::ifstream file;
	file.open(filePath);
	assert(file.is_open());

	//マップチップCSV
	std::stringstream mapChipCsv;
	//ファイルの内容を文字列ストリームにコピー
	mapChipCsv << file.rdbuf();
	//ファイルを閉じる
	file.close();

	//CSVからマップチップデータを読み込む
	for (uint32_t i = 0; i < 10; ++i) {
		std::string line;
		getline(mapChipCsv, line);

		//1行分の文字列をストリームに変換して解析しやすくする
		std::istringstream line_stream(line);

		std::vector<int> a;
		mapchip->push_back(a);

		for (uint32_t j = 0; j < 10; ++j) {
			std::string word;
			getline(line_stream, word, ',');

			if (word == "0") {
				mapchip->at(mapchip->size() - 1).push_back(0);
			}
			if (word == "1") {
				mapchip->at(mapchip->size() - 1).push_back(1);
			}
			if (word == "2") {
				mapchip->at(mapchip->size() - 1).push_back(2);
			}
			Sleep(100);
		}
	}
}

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(_In_ HINSTANCE, _In_opt_ HINSTANCE, _In_ LPSTR, _In_ int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	std::vector<std::vector<int>> mapchip;

	bool exit = false;
	std::mutex mutex;

	// バックグラウンドループ
	std::thread th([&]() {
		while (!exit) {
			std::lock_guard<std::mutex> lock(mutex);
			if (mapchip.size() < 10) {
				LoadMapChipCsv("map.csv", &mapchip);
			}
		}
	});

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

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		for (int i = 0; i < mapchip.size(); i++) {
			for (int j = 0; j < mapchip[i].size(); j++) {

				unsigned int color{};

				if (mapchip[i][j] == 0) {
					color = WHITE;
				} else if (mapchip[i][j] == 1) {
					color = RED;
				} else if (mapchip[i][j] == 2) {
					color = BLUE;
				}

				Novice::DrawBox(20 * i, 20 * j, 20, 20, 0, color, kFillModeSolid);
			}
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

	exit = true;
	th.join();

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
