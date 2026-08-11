#pragma once

#include "MathHelper.h"

class Camera {
public:
	static Camera* Get();
	void OnNewFrame();
	//External info
	void SetPosition(const Vector3& pos);
	void SetDirection(const Vector3& dir);

	//Internal info
	void SetNearPlane(float nearPlane);
	void SetFarPlane(float FarPlane);
	void SetFOV(float fov);

	Matrix4 GetViewMatrix() const;
	Matrix4 GetProjectionMatric() const;

	const Vector3& GetPosition() const;
	const Vector3& GetDirection() const;
private:
	Vector3 mPosition;
	Vector3 mDirection;
	float mNearPlane;
	float mFarPlane;
	float mFOV;
};