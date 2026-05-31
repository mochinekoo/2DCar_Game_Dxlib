#pragma once
#include <string>
#include <vector>

class Box2DCollider;
class BaseObject {
protected:
	std::string name_;
	bool isAlive_;
	std::vector<Box2DCollider*> colliderList;
public:
	BaseObject(const std::string name, const bool isAlive);
	~BaseObject() {};

	virtual void Init() = 0;
	virtual void Update() = 0;
	virtual void Draw() = 0;
	virtual void Release() = 0;
	bool IsAlive() const { return isAlive_; };
};