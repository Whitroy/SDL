#ifndef CIRCLE_COMPONENT_H
#define CIRCLE_COMPONENT_H
#include"GameEssentials/Component.h"

class CircleComponent :public Component
{
private:
	float mRadius{};
public:
	CircleComponent(class Actor* owner);

	inline void SetRadius(const float radius) { mRadius = radius; }
	inline float GetRadius() const { return mRadius; }

	const Actor* GetOwner() const;
};
bool Intersect(const CircleComponent& a, const CircleComponent& b);

#endif // !CIRCLE_COMPONENT_H
