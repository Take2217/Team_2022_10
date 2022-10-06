#include "InGameScene.h"
#include "Datas.h"
#include "Camera.h"
#include "Quad.h"
#include "KeyMouseInput.h"
#include "Game.h"

InGameScene::InGameScene(Game& pGame) : BaseScene(pGame)
{
}

void InGameScene::Init() {
	getCameraMain().setScale(1.0f);
	getGame().ChangePhase(Game::kUpdate);
}
void InGameScene::Update() {
	if (0 < Mouse::GetMouseWheel()) {
		getCameraMain().MoveScale(0.03f);
	}
	if (Mouse::GetMouseWheel() < 0) {
		getCameraMain().MoveScale(-0.03f);
	}

	if (Mouse::IsPressedButton(0)) {
		getCameraMain().MoveTheta(0.05f);
	}
	if (Mouse::IsPressedButton(1)) {
		getCameraMain().MoveTheta(-0.05f);
	}

	getCameraMain().CameraShake({130.0f,0.0f},{ -3.0f ,0.0f },30.0f );
}
void InGameScene::Draw() {
	getCameraUI().DrawQuad({ {0,0},1920,1080 }, Datas::BackGroundTex);
}
void InGameScene::Finalise() {

}