#pragma once
#include <XColors.h>


class MaterialManager {
public:
	static MaterialManager* Get();
	void OnNewFrame();
	void SetmaterialEmissive(const X::Color& color);
	void SetmaterialAmbient(const X::Color& color);
	void SetmaterialDiffuse(const X::Color& color);
	void SetmaterialSpecular(const X::Color& color);
	void SetmaterialShininess(float shininess);

	const X::Color& GetMaterialEmissive() const;
	const X::Color& GetMaterialAmbient() const;
	const X::Color& GetMaterialDiffuse() const;
	const X::Color& GetMaterialSpecular() const;
	const float GetMaterialShininess() const;
private:
	X::Color mEmissive = X::Colors::Black;
	X::Color mAmbient = X::Colors::White;
	X::Color mDiffuse = X::Colors::White;
	X::Color mSpecular = X::Colors::White;
	float mShininess = 10.0f;
};