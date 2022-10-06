#include "GameObject.h"
#include "Game.h"

GameObject::GameObject(Game& pGame) :pGame(pGame)
{
}

GameObject::~GameObject(){}

Game& GameObject::getGame() const {
	return pGame;
}
float GameObject::getDeltaTime(){
	return pGame.getDeltaTime();
}
Camera& GameObject::getCameraMain() {
	return pGame.getCameraMain();
}
Camera& GameObject::getCameraSub() {
	return pGame.getCameraSub();
}
Camera& GameObject::getCameraUI() {
	return pGame.getCameraUI();
}