#ifndef APPLICATION2_H
#define APPLICATION2_H

#include "GameEssentials/Game.h"
#include<vector>
#include <unordered_map>

namespace SDLChapter3
{
	class Application2 : public Game
	{
	private:
		 class BattleShip* mShip{};
		 std::vector<class Asteroid*> mAsteroids{};

	public:
		Application2(int width, int height);

		void AddAsteroid(class Asteroid* ast);
		void RemoveAsteroid(class Asteroid* ast);

		std::vector<class Asteroid*>& GetAsteroids() { return mAsteroids; }

	private:
		void LoadData() override;
	};
}

#endif // !GAME2_H
