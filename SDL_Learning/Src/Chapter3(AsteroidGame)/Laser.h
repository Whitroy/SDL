#pragma once
#include"GameEssentials/Actor.h"

namespace SDLChapter3
{
	class Laser :public Actor
	{
	public:
		Laser(class Application2* game);
		void UpdateActor(float deltaTime) override;
		void Move(const Vector2& fwd);
	private:
		class CircleComponent* mCircle{};
		float mDeathTimer{};
		Vector2 mForward{};
		float mSpeed{};
	};
}