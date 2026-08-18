#include "MaterialManager.h"


MaterialManager* MaterialManager::Get() {
	static MaterialManager sInstance;
	return &sInstance;
}


void MaterialManager::OnNewFrame() {
	mEmissive = X::Colors::Black;
	mAmbient = X::Colors::White;
	mDiffuse = X::Colors::White;
	mSpecular = X::Colors::White;
	mShininess = 10.0f;
}

void MaterialManager::SetmaterialEmissive(const X::Color& color)
{
	mEmissive = color;
}

void MaterialManager::SetmaterialAmbient(const X::Color& color)
{
	mAmbient = color;
}

void MaterialManager::SetmaterialDiffuse(const X::Color& color)
{
	mDiffuse = color;
}

void MaterialManager::SetmaterialSpecular(const X::Color& color)
{
	mSpecular = color;
}

void MaterialManager::SetmaterialShininess(float shininess)
{
	mShininess = shininess;
}

const X::Color& MaterialManager::GetMaterialEmissive() const
{
	return mEmissive;
}

const X::Color& MaterialManager::GetMaterialAmbient() const
{
	return mAmbient;
}

const X::Color& MaterialManager::GetMaterialDiffuse() const
{
	return mDiffuse;
}

const X::Color& MaterialManager::GetMaterialSpecular() const
{
	return mSpecular;
}

const float MaterialManager::GetMaterialShininess() const
{
	return mShininess;
}
