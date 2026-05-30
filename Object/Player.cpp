#include <DxLib.h>
#include "Player.h"
#include "../framework.h"
#include "../Scene/RootScene.h"


Player::Player(const Location2D& loc)
	: Base2DObject("Player", true, loc, Vector2D{0.0f, 0.0f}) {
	direction_ = { 1, 0 };
}

Player::~Player() {
}

void Player::Init() {
}

void Player::Update() {
	static int x = 0, y = 0;
	GetMousePoint(&x, &y);

	Location2D nextPos = {};
	nextPos.x_ = x;
	nextPos.y_ = y;

	if (!stage->IsCollstion(nextPos)) {
		location_ = nextPos;
	}
}

void Player::Draw() {
	DrawCircle(location_.x_, location_.y_, PLAYER_RADIUS, GetColor(255, 0, 0));
}

void Player::Release() {
}
