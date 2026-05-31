#pragma once
#include <DxLib.h>
#include "BaseScene.h"
#include "../Object/Stage.h"
#include "../Object/Player.h"

class RootScene : public BaseScene {
private:
protected:
public:
	RootScene();
	~RootScene();

	void Init() override;
	void Update() override;
	void Draw() override;
	void Release() override;
};