#pragma once

class Texture;
class Sound;

class Datas
{
public:
    // スクリーン
    static constexpr char WINDOW_TITLE[] = "Title";
    static constexpr float SCREEN_HEIGHT = 1080.0f;
    static constexpr float SCREEN_WIDTH = 1920.0f;
    static constexpr float SCREEN_HALF_HEIGHT = SCREEN_HEIGHT / 2;
    static constexpr float SCREEN_HALF_WIDTH = SCREEN_WIDTH / 2;
    
    // テクスチャ
    static Texture BackGroundTex;

    // サウンド
    // static Sound Bgm;

private:
    Datas(){}
    ~Datas(){}
};