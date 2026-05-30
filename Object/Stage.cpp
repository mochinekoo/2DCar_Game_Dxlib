#include <DxLib.h>
#include "Stage.h"
#include "../framework.h"
#include "Player.h"
#include "../ImGUI/imgui.h"

Stage::Stage()
	: Base2DObject("Stage", true, Location2D{0.0f, 0.0f}, Vector2D{0.0f, 0.0f}) {
}

Stage::~Stage() {
}

void Stage::Init() {
}

void Stage::Update() {
}

void Stage::Draw() {
	DrawCircle(GameScreen::WIDTH / 2, GameScreen::HEIGHT / 2, CENTER_RADIUS, GetColor(0, 255, 0));
}

void Stage::Release() {
}

bool Stage::IsCollstion(const Location2D& loc) {
	const float radius = CENTER_RADIUS + PLAYER_RADIUS;
	float centerDistance = loc.Distance(Location2D{ GameScreen::WIDTH / 2, GameScreen::HEIGHT / 2});

	if (centerDistance <= radius) {
		return true;
	}
	return false;
}
