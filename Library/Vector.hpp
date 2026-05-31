#pragma once
#include <cmath>

/// <summary>
/// ベクトルのクラス。（※DxLibはC言語なので、オペレーター関数を加えたものです。）
/// </summary>
class Vector3D {
public:
	float x_, y_, z_;

	Vector3D()  {
		x_ = 0;
		y_ = 0;
		z_ = 0;
	}

	Vector3D(float x, float y, float z)  {
		x_ = x;
		y_ = y;
		z_ = z;
	}

	float Length() const {
		return sqrt(x_ * x_ + y_ * y_ + z_ * z_);
	}

	Vector3D Add(float x, float y, float z) const {
		float newX = x_ + x;
		float newY = y_ + y;
		float newZ = z_ + z;
		return Vector3D(newX, newY, newZ);
	}

	Vector3D Add(const Vector3D& other) const {
		return Add(other.x_, other.y_, other.z_);
	}

	Vector3D operator+(const Vector3D& other) const {
		return Add(other);
	}

	Vector3D Subtract(float x, float y, float z) const {
		float newX = x_ - x;
		float newY = y_ - y;
		float newZ = z_ - z;
		return Vector3D(newX, newY, newZ);
	}

	Vector3D Subtract(const Vector3D& other) const {
		return Subtract(other.x_, other.y_, other.z_);
	}

	Vector3D operator-(const Vector3D& other) const {
		return Subtract(other);
	}

	Vector3D Scalar(float scalar) const {
		float newX = x_ * scalar;
		float newY = y_ * scalar;
		float newZ = z_ * scalar;
		return Vector3D(newX, newY, newZ);
	}

	float Dot(const Vector3D& other) const {
		return x_ * other.x_ + y_ * other.y_ + z_ * other.z_;
	}

	Vector3D Multiply(const Vector3D& other) const {
		float newX = x_ * other.x_;
		float newY = y_ * other.y_;
		float newZ = z_ * other.z_;
		return Vector3D(newX, newY, newZ);
	}

	Vector3D Cross(const Vector3D& other) const {
		float newX = y_ * other.z_ - z_ * other.y_;
		float newY = z_ * other.x_ - x_ * other.z_;
		float newZ = x_ * other.y_ - y_ * other.x_;
		return Vector3D(newX, newY, newZ);
	}

	Vector3D Normalize() const {
		float len = Length();
		if (len == 0) {
			return Vector3D();
		}
		return Vector3D(x_ / len, y_ / len, z_ / len);
	}

	float Distance(const Vector3D& other) const {
		float newX = (x_ - other.x_) * (x_ - other.x_);
		float newY = (y_ - other.y_) * (y_ - other.y_);
		float newZ = (z_ - other.z_) * (z_ - other.z_);
		return sqrt(newX + newY + newZ);
	}

};


class Vector2D {
public:
	float x_, y_;

	Vector2D() {
		x_ = 0;
		y_ = 0;
	}

	Vector2D(float x, float y) {
		x_ = x;
		y_ = y;
	}

	float Length() const {
		return sqrt(x_ * x_ + y_ * y_);
	}

	Vector2D Add(float x, float y) const {
		float newX = x_ + x;
		float newY = y_ + y;
		return Vector2D(newX, newY);
	}

	Vector2D Add(const Vector2D& other) const {
		return Add(other.x_, other.y_);
	}

	Vector2D operator+(const Vector2D& other) const {
		return Add(other);
	}

	Vector2D Subtract(float x, float y) const {
		float newX = x_ - x;
		float newY = y_ - y;
		return Vector2D(newX, newY);
	}

	Vector2D Subtract(const Vector2D& other) const {
		return Subtract(other.x_, other.y_);
	}

	Vector2D operator-(const Vector2D& other) const {
		return Subtract(other);
	}

	Vector2D Scalar(float scalar) const {
		float newX = x_ * scalar;
		float newY = y_ * scalar;
		return Vector2D(newX, newY);
	}

	float Dot(const Vector2D& other) const {
		return x_ * other.x_ + y_ * other.y_;
	}

	Vector2D Multiply(const Vector2D& other) const {
		float newX = x_ * other.x_;
		float newY = y_ * other.y_;
		return Vector2D(newX, newY);
	}

	Vector2D Normalize() const {
		float len = Length();
		if (len == 0) {
			return Vector2D();
		}
		return Vector2D(x_ / len, y_ / len);
	}

	float Distance(const Vector2D& other) const {
		float newX = (x_ - other.x_) * (x_ - other.x_);
		float newY = (y_ - other.y_) * (y_ - other.y_);
		return sqrt(newX + newY);
	}

	static Vector2D FromAngle(float angle) {
		float x = cos(angle);
		float y = sin(angle);
		return {x, y};
	}

};