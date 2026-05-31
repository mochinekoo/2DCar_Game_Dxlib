#pragma once
#include "../Library/Location.hpp"
#include "../Library/Vector.hpp"
#include "Base2DObject.h"

namespace {
	float PLAYER_RADIUS = 15.0f;
}

class Player : public Base2DObject {
private:
	float angle_;
public:
	Player(const Location2D& loc);
	~Player();

	void Init() override;
	void Update() override;
	void Draw() override;
	void Release() override;
};