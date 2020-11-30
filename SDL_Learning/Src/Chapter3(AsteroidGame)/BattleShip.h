#ifndef BATTLE_SHIP_H
#define BATTLE_SHIP_H

#include"GameEssentials/Actor.h"

namespace SDLChapter3
{
	class  BattleShip : public Actor
	{
	private:
		float mLaserCoolDown{};
		class SpriteComponent* mSc{};
		class InputComponent* mIc{};
		class CircleComponent* mCc{};

		float mInvinsibleTime{};
		bool mIsInvinsible{};
	public:
		BattleShip(class Application2* game);

		void UpdateActor(float deltaTime) override;
		void ActorInput(const uint8_t* keyState) override;
	};
}
#endif // !BATTLE_SHIP_H
