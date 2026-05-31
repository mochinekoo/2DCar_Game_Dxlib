#include "Collider.h"
#include <DxLib.h>

Box2DCollider::Box2DCollider(Base2DObject* obj, const float top, const float bottom, const float left, const float right)
    : Base2DObject("Box2DCollider", true, obj->GetLocation(), obj->GetVector()) {
    this->top = top;
    this->bottom = bottom;
    this->left = left;
    this->right = right;
    isShowing = false;
    colliderObj_ = obj;
}

Box2DCollider::~Box2DCollider() {
}

void Box2DCollider::Init() {
}

void Box2DCollider::Update() {
    location_ = colliderObj_->GetLocation();
}

void Box2DCollider::Draw() {
    if (isShowing) {
        int x1 = location_.x_ - left;
        int y1 = location_.y_ - top;
        int x2 = location_.x_ + right;
        int y2 = location_.y_ + bottom;
        DrawBox(x1, y1, x2, y2, GetColor(255, 0, 0), FALSE);
    }
}

void Box2DCollider::Release() {
}

bool Box2DCollider::IsCollstion() {
    return false;
}
