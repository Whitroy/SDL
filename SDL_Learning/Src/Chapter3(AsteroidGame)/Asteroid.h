#ifndef ASTEROID_H
#define ASTEROID_H

#include"GameEssentials/Actor.h"
#include"GameEssentials/CircleComponent.h"

namespace SDLChapter3
{
	class Asteroid :public Actor
	{
	private:
		int mId{};
		static int IDGenerator;
		CircleComponent* mCircle{};
	public:
		Asteroid(class Application2* game);
		~Asteroid();
		inline CircleComponent* GetCircle() const { return mCircle; }
		inline int GetID()const { return mId; }
	};
}

#endif // !ASTEROID_H
