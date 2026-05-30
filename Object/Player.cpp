#include <DxLib.h>
#include "Player.h"
#include "../framework.h"
#include "../Scene/RootScene.h"
#include "../ImGUI/imgui.h"


Player::Player(const Location2D& loc)
	: Base2DObject("Player", true, loc, Vector2D{0.0f, 0.0f}) {
	direction_ = { 1, 0 };
}

Player::~Player() {
}

void Player::Init() {
}

void Player::Update() {

	Location2D nextPos = location_;
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		vector_ = direction_;
		nextPos = location_ + Location2D{vector_.x_, vector_.y_};
	}
	else {

	}

	if (!stage->IsCollstion(nextPos)) {
		location_ = nextPos;
	}
}

void Player::Draw() {
	DrawCircle(location_.x_, location_.y_, PLAYER_RADIUS, GetColor(255, 0, 0));

	ImGui::Begin("Player");
	ImGui::InputFloat("dirX", &direction_.x_);
	ImGui::InputFloat("dirY", &direction_.y_);
	ImGui::End();
}

void Player::Release() {
}
