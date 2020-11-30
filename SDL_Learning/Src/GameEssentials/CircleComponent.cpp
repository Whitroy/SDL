#include "CircleComponent.h"
#include"Math/Math.h"
#include"Actor.h"
CircleComponent::CircleComponent(Actor* owner)
	:Component{ owner }
{
}

const Actor* CircleComponent::GetOwner() const
{
	return mOwner;
}

bool Intersect(const CircleComponent& a, const CircleComponent& b)
{
	// Calculate distance squared

	Vector2 pos1 = Vector2{ a.GetOwner()->GetPosition() };
	Vector2 pos2 = Vector2{ b.GetOwner()->GetPosition() };

	Vector2 diff = pos1 - pos2;

	float distSq = diff.LengthSq();

	// Calculate sum of radii squared
	float radiiSq = a.GetRadius() + b.GetRadius();
	radiiSq *= radiiSq;
	return distSq <= radiiSq;
}
