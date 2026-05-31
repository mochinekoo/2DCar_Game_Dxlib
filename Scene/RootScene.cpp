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
}

RootScene::~RootScene() {
}

void RootScene::Init() {
	new Stage();
	new Player(Location2D{30, 30});
}

void RootScene::Update() {
}

void RootScene::Draw() {
}

void RootScene::Release() {
}	
