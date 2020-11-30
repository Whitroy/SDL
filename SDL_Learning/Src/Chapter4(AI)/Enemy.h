#ifndef ENEMY_H
#define ENEMY_H

#include"GameEssentials/Actor.h"
namespace SDLChapter4
{
	class Enemy :public Actor
	{
	private:
		class CircleComponent* mCircle{};
	public:
		Enemy(class Application4* game);
		~Enemy();
		void UpdateActor(float deltaTime) override;
		class CircleComponent* GetCircle() { return mCircle; }
	};
}

#endif // !ENEMY_H