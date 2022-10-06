#pragma once
#include "BaseScene.h"

class TitleScene : public BaseScene
{
public:
	TitleScene(Game& pGame);

	void Init() override;
	void Update() override;
	void Draw() override;
	void Finalise() override;

private:

};