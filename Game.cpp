#include "Game.h"

#include <Novice.h>
#include "Screen.h"
#include "KeyMouseInput.h"
#include "ControllerInput.h"
#include "TitleScene.h"
#include "InGameScene.h"
#include "LoadScene.h"
#include "Delta.h"
#include "Texture.h"
#include "Datas.h"
#include "MyFunc.h"
#include "Quad.h"

Game::Game(): mCameraMain(*this), mCameraSub(*this), mCameraUI(*this)
{
    // イニシャライズ
    Novice::Initialize(Datas::WINDOW_TITLE, static_cast<int>(Datas::SCREEN_WIDTH), static_cast<int>(Datas::SCREEN_HEIGHT));

    // Srand
    My::SetSrand();

    // シーンポインタ
    pScene[kTitleScene] = new TitleScene(*this);
    pScene[kInGameScene] = new InGameScene(*this);
    pScene[kLoadScene] = new LoadScene(*this);

    // 初期シーンをタイトルに
    mNowScene = kTitleScene;

    // 初期フェーズをイニットに
    mNowPhase = kInit;

    // マウスのテクスチャを設定
    Mouse::SetTexture(Novice::LoadTexture("./Resources/UI/mouse.png"));

    // マウスを非表示
    Novice::SetMouseCursorVisibility(0);
}

Game::~Game()
{
    // シーンを全てdelete
    for (int i = 0; i < kSceneNum; i++) {
        delete pScene[i];
    }
    // ファイナライズ
    Novice::Finalize();
}

float Game::getDeltaTime() const {
    return Delta::getDeltaTime();
}

Camera& Game::getCameraMain() {
    return mCameraMain;
}
Camera& Game::getCameraSub() {
    return mCameraSub;
}
Camera& Game::getCameraUI() {
    return mCameraUI;
}

/// @brief ゲームループ
void Game::Run(){
	while (Novice::ProcessMessage() == 0) {
        // フレーム開始
		BeginFrame();
        
        // 更新処理
        Update();

        // 描画処理
		Draw();

        // フレーム終了
        EndFrame();
		
        // ESC押したら終了
		if (Key::IsPressed(DIK_ESCAPE)) {
			break;
		}
	}
}

void Game::ChangeScene(Scene scene) {
    mNowScene = scene;
}

void Game::ChangePhase(Process process) {
    mNowPhase = process;
}

/// @brief 開始時処理
void Game::BeginFrame(){
    // フレーム開始
    Novice::BeginFrame();
    
    // デルタタイム取得
    Delta::Update();

    // 入力取得
    Key::SetState();
	Mouse::SetState();
	Controller::SetState();
}

/// @brief 更新処理
void Game::Update(){
    switch (mNowPhase)
    {
    case Game::kInit:
        // 現在のシーンに応じて初期化処理(フェードイン)
        pScene[mNowScene]->Init();
        break;
    case Game::kUpdate:
        // 現在のシーンに応じて更新処理
        pScene[mNowScene]->Update();
        break;
    case Game::kFinalise:
        // 現在のシーンに応じて終了処理(フェードアウト)
        pScene[mNowScene]->Finalise();
        break;
    case Game::kPhaseNum:
    default:
        break;
    }
    mCameraMain.Update();
    mCameraSub.Update();
    mCameraUI.Update();
}

/// @brief 描画処理
void Game::Draw(){
    // 現在のシーンに応じて描画処理
    pScene[mNowScene]->Draw();
    Mouse::Draw();
}

/// @brief 終了時処理
void Game::EndFrame(){
    // フレーム終了
    Novice::EndFrame();
}

