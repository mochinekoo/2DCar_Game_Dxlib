#include <DxLib.h>
#include "Player.h"
#include "../framework.h"
#include "../Scene/RootScene.h"
#include "../ImGUI/imgui.h"
#include "../Manager/ObjectManager.h"


Player::Player(const Location2D& loc)
	: Base2DObject("Player", true, loc, Vector2D{0.0f, 0.0f}) {
	direction_ = { 1, 0 };
	angle_ = 0;
	imageHandle_ = -1;
}

Player::~Player() {
}

void Player::Init() {
	imageHandle_ = LoadGraph("player.png");
}

void Player::Update() {

	Location2D nextPos = location_;
	if (CheckHitKey(KEY_INPUT_SPACE)) {
		if (vector_.x_ < 5 && vector_.y_ < 5) {
			vector_ = vector_ + direction_;
		}
		
	}

	if (CheckHitKey(KEY_INPUT_LEFT)) {
		angle_-=0.1;
	}
	if (CheckHitKey(KEY_INPUT_RIGHT)) {
		angle_+=0.1;
	}
	direction_ = Vector2D::FromAngle(angle_);

	nextPos = location_ + Location2D{ vector_.x_, vector_.y_ };
	vector_.x_ *= 0.99;
	vector_.y_ *= 0.99;

	Stage* stage = ObjectManager::FindObject<Stage*>();
	if (!stage->IsCollstion(nextPos)) {
		location_ = nextPos;
	}
	else {
		vector_.x_ = -direction_.x_ * 3;
		vector_.y_ = -direction_.y_ * 3;
	}
}

void Player::Draw() {
	// DrawCircle(location_.x_, location_.y_, PLAYER_RADIUS, GetColor(255, 0, 0));
	DrawRotaGraph(location_.x_, location_.y_, 1.0, angle_, imageHandle_, TRUE);

	ImGui::Begin("Player");
	ImGui::InputFloat("dirX", &direction_.x_);
	ImGui::InputFloat("dirY", &direction_.y_);
	ImGui::InputFloat("vecX", &vector_.x_);
	ImGui::InputFloat("vecY", &vector_.y_);
	ImGui::End();
}

void Player::Release() {
}
