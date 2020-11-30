#ifndef BULLET_H
#define BULLET_H

#include "GameEssentials/Actor.h"

namespace SDLChapter4
{
	class Bullet : public Actor
	{
	public:
		Bullet(class Application4* game);
		void UpdateActor(float deltaTime) override;
		friend class Tower;
	private:
		class CircleComponent* mCircle;
		class Tower* mTower;
		float mLiveTime{};
	};
}

#endif // !BULLET_H
