#include "LightTypes.h"
#include "Camera.h"
#include "MaterialManager.h"
X::Color DirectionalLight::ComputeLightColor(const Vector3& position, const Vector3& normal) {
	Camera* camera = Camera::Get();
	MaterialManager* mm = MaterialManager::Get();

	X::Color ambient = mAmbient * mm->GetMaterialAmbient();

	Vector3 L = -mDirection;
	float dot = X::Math::Max(MathHelper::Dot(L, normal), 0.0f);
	X::Color diffuse = mDiffuse * mm->GetMaterialDiffuse() * dot;

	Vector3 v = MathHelper::Normalize(camera->GetPosition() - position);
	Vector3 r = MathHelper::Normalize(L + v);
	float fallOf = X::Math::Max((float)pow(MathHelper::Dot(r, normal), mm->GetMaterialShininess()), 0.0f);
	X::Color specular = mSpecular * mm->GetMaterialSpecular() * fallOf;

	return ambient + diffuse + specular;
}
void DirectionalLight::SetDirection(const Vector3& direction) {
	mDirection = MathHelper::Normalize(direction);
}
X::Color PointLight::ComputeLightColor(const Vector3& position, const Vector3& normal) {
	Camera* camera = Camera::Get();
	MaterialManager* mm = MaterialManager::Get();

	Vector3 L = mPosition - position;
	float distance = MathHelper::Magnitude(L);
	L /= distance;

	float attenuation = 1.0f / (mKConstant + (mKLinear * distance) + (mKQuadratic * distance * distance));
	float iL = X::Math::Clamp(attenuation, 0.0f, 1.0f);

	X::Color ambient = mAmbient * mm->GetMaterialAmbient();

	float dot = X::Math::Max(MathHelper::Dot(L, normal), 0.0f);
	X::Color diffuse = mDiffuse * mm->GetMaterialDiffuse() * dot * iL;

	Vector3 v = MathHelper::Normalize(camera->GetPosition() - position);
	Vector3 r = MathHelper::Normalize(L + v);
	float fallOf = X::Math::Max((float)pow(MathHelper::Dot(r, normal), mm->GetMaterialShininess()), 0.0f);
	X::Color specular = mSpecular * mm->GetMaterialSpecular() * fallOf * iL;

	return ambient + diffuse + specular;
}

void PointLight::SetPosition(const Vector3& position) {
	mPosition = position;
}
void PointLight::SetAttenuation(float kConstant, float kLinear, float kQuadratic) {
	mKConstant = kConstant;
	mKLinear = kLinear;
	mKQuadratic = kQuadratic;
}