#ifndef TOWER_H
#define TOWER_H

#include"GameEssentials/Actor.h"

namespace SDLChapter4
{
	class Tower : public Actor
	{
	public:
		Tower(class Application4* game);
		void UpdateActor(float deltaTime) override;
	private:
		class MoveComponent* mMove;
		float mNextAttack;
		const float AttackTime = 2.5f;
		const float AttackRange = 100.0f;
	};
}
#endif // ! TOWER_H