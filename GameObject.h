#pragma once

class Game;
class Camera;

class GameObject
{
public:
	GameObject(Game& pGame);
	virtual ~GameObject();

	Game& getGame() const;
	float getDeltaTime();
	Camera& getCameraMain();
	Camera& getCameraSub();
	Camera& getCameraUI();
private:
	/// @brief ゲームのポインタ
	Game& pGame;
};