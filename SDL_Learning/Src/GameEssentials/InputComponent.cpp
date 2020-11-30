#include "InputComponent.h"
#include"Actor.h"

InputComponent::InputComponent(Actor* Owner)
	:MoveComponent{ Owner }
{
}

void InputComponent::ProcessInput(const uint8_t* keystate)
{
	Vector2 force = Vector2::Zero;

	if (keystate[mForwardKey])
	{
		force = Vector2{ mOwner->GetForward() * mMaxForwardSpeed };
	}
	if (keystate[mBackKey])
	{
		force = Vector2{ mOwner->GetForward() * -mMaxForwardSpeed };
	}

	SetVelocity(Vector2::Zero);
	AddForce(force);

	float angularSpeed = 0.0f;

	if (keystate[mClockwiseKey])
	{
		angularSpeed += mMaxAngularSpeed;
	}
	if (keystate[mCounterClockwiseKey])
	{
		angularSpeed -= mMaxAngularSpeed;
	}
	SetAngularSpeed(angularSpeed);
}