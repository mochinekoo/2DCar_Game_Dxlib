#pragma once
#include "Base2DObject.h"

namespace {
	float CENTER_RADIUS = 100.0f;
}

class Stage : public Base2DObject {
private:
public:
	Stage();
	~Stage();

	void Init() override;
	void Update() override;
	void Draw() override;
	void Release() override;

	bool IsCollstion(const Location2D& loc);
};