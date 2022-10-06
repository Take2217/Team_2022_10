#include "LoadScene.h"
#include "Load.h"
#include "Game.h"
#include <Novice.h>

LoadScene::LoadScene(Game& pGame) : BaseScene(pGame)
{
}

void LoadScene::Init() {
	getGame().ChangePhase(Game::kUpdate);
}
void LoadScene::Update() {
	// スレッドが開始されていなかったら
	if (!mThread.joinable()) {
		// 開始
		mThread = std::thread(Load::SetLoad, Load::kMain);
	}
	
	// ロードが終わっていたら
	if (Load::IsEnd(Load::kMain)) {
		// ファイナライズに移行
		getGame().ChangePhase(Game::kFinalise);

		// スレッドと同期
		mThread.join();
	}
}
void LoadScene::Draw() {

}
void LoadScene::Finalise() {
	getGame().ChangeScene(Game::kInGameScene);
	getGame().ChangePhase(Game::kInit);
}