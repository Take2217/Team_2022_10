#pragma once
#include <time.h>

/// @brief デルタタイムクラス
class Delta
{
private:
	/// @brief 目標FPS
	static constexpr float kFPS = 60.0f;

	/// @brief デルタタイム
	static float mDeltaTime;

	/// @brief 現在フレームの時間
	static clock_t mNowTime;

	/// @brief 前のフレームの時間
	static clock_t mOldTime;
public:
	/// @brief 更新(デルタタイムをアップデート)
	static void Update();
	
	static float getDeltaTime();
private:
	Delta();
	~Delta();
};

