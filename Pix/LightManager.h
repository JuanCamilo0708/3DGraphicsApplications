#pragma once

#include <XEngine.h>
#include "Light.h"

class LightManager {
public:
	static LightManager* Get();
	void OnNewFrame();

	void SetLightAmbient(const X::Color& color);
	void SetLightDiffuse(const X::Color& color);
	void SetLightSpecular(const X::Color& color);

	//directional light
	void AddDirectionalLight(const Vector3& direction);
	//point light
	void AddPointLight(const Vector3& position, float kConstant, float kLinear, float kQuadratic);
	X::Color ComputeLightColor(const Vector3& position, const Vector3& normal);
	//spotLight
	void AddSpotLight(const Vector3& position, const Vector3& direction, float kConstant, float kLinear, float kQuadratic, float angle, float decay);

private:
	std::vector<std::unique_ptr<Light>> mLights;
	X::Color mAmbient = X::Colors::White;
	X::Color mDiffuse = X::Colors::White;
	X::Color mSpecular = X::Colors::White;
};