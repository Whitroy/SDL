#include "NavComponent.h"
#include"GameEssentials/MoveComponent.h"
#include"GameEssentials/Actor.h"
#include"Tile.h"
SDLChapter4::NavComponent::NavComponent(Actor* owner)
	:MoveComponent{ owner }, mNextNode{ nullptr }
{
}

void SDLChapter4::NavComponent::TurnTo(const Vector2& pos)
{
	Vector2 dir = pos - mOwner->GetPosition();

	float angle = Math::Atan2(-dir.y, dir.x);

	mOwner->SetRotation(angle);
}

void SDLChapter4::NavComponent::Update(float deltaTime)
{
	if (mNextNode)
	{
		Vector2 diff = mOwner->GetPosition() - mNextNode->GetPosition();

		if (diff.Length() <= 2.0f)
		{
			mNextNode = mNextNode->GetParent();
			TurnTo(mNextNode->GetPosition());
		}
	}
	MoveComponent::Update(deltaTime);
}

void SDLChapter4::NavComponent::StartPath(const Tile* start)
{
	mNextNode = start->GetParent();
	TurnTo(mNextNode->GetPosition());
}
