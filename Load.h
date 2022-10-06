#pragma once

class Load
{
   
public:
    // ローディング
    enum LoadPhase {
        kMain,
        kStage1,

        kPhaseNum
    };

    /// @brief ロードを依頼する関数
    /// @param phase どのフェーズをロードするか
    static void SetLoad(LoadPhase phase);

    /// @brief 終わっているか
    /// @param phase どのフェーズをロードするか
    /// @return 終わっていたら : true , 終わっていなかったら : false
    static bool IsEnd(LoadPhase phase);

private:
    // ロードが終わっているかフラグの配列
    static bool mIsEnd[kPhaseNum];
};