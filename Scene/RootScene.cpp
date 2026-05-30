#include <DxLib.h>
#include "BaseScene.h"
#include "RootScene.h"
#include <array>
#include "RootScene.h"

namespace {
}

RootScene::RootScene()
	: BaseScene("RootScene") {
	sceneCounter_ = 0;
	stage = nullptr;
	player = nullptr;
}

RootScene::~RootScene() {
}

void RootScene::Init() {
	stage = new Stage();
	stage->Init();
	player = new Player(Location2D{30, 30});
	player->Init();
}

void RootScene::Update() {
	if (stage == nullptr || player == nullptr) return;
	stage->Update();
	player->Update();
}

void RootScene::Draw() {
	if (stage == nullptr || player == nullptr) return;
	stage->Draw();
	player->Draw();
}

void RootScene::Release() {
	player->Release();
	stage->Release();
}	
