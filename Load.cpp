#include "Load.h"
#include "Texture.h"
#include "Sound.h"
#include "Datas.h"
#include <Novice.h>

// 初期化

bool Load::mIsEnd[kPhaseNum] = { 0 };

/// @brief ロードを依頼する関数
/// @param phase どのフェーズをロードするか
void Load::SetLoad(LoadPhase phase){
    switch (phase)
    {
    case kMain:
        // ハンドルをセット
        Datas::BackGroundTex.SetHandle(Novice::LoadTexture("./Resources/Stage/Bg.png"));

        // ロードが完了したらtrue
        mIsEnd[kMain] = true;
        break;
    case kStage1:
        break;
    case kPhaseNum:
    default:
        break;
    }
}

/// @brief 終わっているか
/// @param phase どのフェーズをロードするか
/// @return 終わっていたら : true , 終わっていなかったら : false
bool Load::IsEnd(LoadPhase phase) {
    if (mIsEnd[phase]) {
        return true;
    }
    return false;
}