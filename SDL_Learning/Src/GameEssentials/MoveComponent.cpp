#include "MoveComponent.h"
#include"Actor.h"
MoveComponent::MoveComponent(Actor* owner, int updateOrder) :
	Component{ owner ,updateOrder }, mMass{ 1.0f }
{
}

void MoveComponent::Update(float deltaTime)
{
	if (!Math::NearZero(mAngularSpeed))
	{
		float rot = mOwner->GetRotation();
		rot += mAngularSpeed * deltaTime;
		mOwner->SetRotation(rot);
	}

	Vector2 mAcceleration{ mForce * (1 / mMass) };
	mForce = Vector2::Zero;
	mVelocity += mAcceleration * deltaTime;

	if (mVelocity != Vector2::Zero)
	{
		Vector2 pos = mOwner->GetPosition();
		pos += mVelocity * deltaTime;

		// (Screen wrapping code only for asteroids)
		if (pos.x < 0.0f) { pos.x = 1022.0f; }
		else if (pos.x > 1024.0f) { pos.x = 2.0f; }

		if (pos.y < 0.0f) { pos.y = 766.0f; }
		else if (pos.y > 768.0f) { pos.y = 2.0f; }

		mOwner->SetPosition(pos);
	}

}