#include "TitleScene.h"
#include "Datas.h"
#include "Camera.h"
#include "Quad.h"
#include "KeyMouseInput.h"
#include "Game.h"

TitleScene::TitleScene(Game& pGame) : BaseScene(pGame)
{
}

void TitleScene::Init() {
	getGame().ChangePhase(Game::kUpdate);
}
void TitleScene::Update() {
	if (Mouse::IsTriggerButton(0)) {
		getGame().ChangePhase(Game::kFinalise);
	}
}
void TitleScene::Draw() {

}
void TitleScene::Finalise() {
	getGame().ChangePhase(Game::kInit);
	getGame().ChangeScene(Game::kLoadScene);
}