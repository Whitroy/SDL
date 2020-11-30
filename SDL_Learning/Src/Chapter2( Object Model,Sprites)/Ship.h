#pragma once
#include "GameEssentials/Actor.h"
namespace SDLChapter3
{
	class Ship : public Actor
	{
	private:
		float mRightSpeed{};
		float mDownSpeed{};

	public:
		Ship(class Application2* game);
		void UpdateActor(float deltaTime) override;
		void ProcessKeyboard(const uint8_t* state);
		float GetRightSpeed() const { return mRightSpeed; };
		float GetLeftSpeed() const { return mDownSpeed; };
	};
}