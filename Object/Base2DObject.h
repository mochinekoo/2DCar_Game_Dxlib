#pragma once
#include "BaseObject.h"
#include "../Library/Location.hpp"
#include "../Library/Vector.hpp"

class Base2DObject : public BaseObject {
protected:
	Location2D location_;
	Vector2D vector_;
	Vector2D direction_;
public:
	Base2DObject(const std::string name, const bool isAlive, const Location2D& loc, const Vector2D& vec)
		: BaseObject(name, isAlive){
		name_ = name;
		isAlive_ = isAlive;
		location_ = loc;
		vector_ = vec;
	};
	~Base2DObject() {};

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Release() = 0;

	Location2D GetLocation() const { return location_; }
	void SetLocation(const Location2D& loc) { this->location_ = loc; }
	Vector2D GetVector() const { return vector_; }
	void SetVector(const Vector2D& vec) { this->vector_ = vec;  }
	Vector2D GetDirection() const { return direction_; }
	void SetDirection(const Vector2D& dir) { this->direction_ = dir; }
};