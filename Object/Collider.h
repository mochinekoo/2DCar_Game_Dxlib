#pragma once
#include "Base2DObject.h"

class Box2DCollider : public Base2DObject {
private:
	bool isShowing;
	Base2DObject* colliderObj_;
	float top, bottom, left, right;
public:
	Box2DCollider(Base2DObject* obj, const float top, const float bottom, const float left, const float right);
	~Box2DCollider();

	void Init() override;
	void Update() override;
	void Draw() override;
	void Release() override;

	bool IsShown() const { return isShowing; }
	void SetShowing(const bool flag) { this->isShowing = flag; }

	bool IsCollstion();
};