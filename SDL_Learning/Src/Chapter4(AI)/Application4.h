#ifndef APPLICATION_4_H
#define APPLICATION_4_H
#include<string>
#include "GameEssentials/Game.h"
#include<unordered_map>

namespace SDLChapter4
{
	class Application4: public Game
	{
	public:
		Application4(int width, int height);

		class Grid* GetGrid() const { return mGrid; }
		std::vector<class Enemy*>& GetEnemies() { return mEnemies; }
		class Enemy* GetNearestEnemy(const Vector2& pos);

	private:

		void LoadData() override;
		
		std::vector<class Enemy*> mEnemies;
		class Grid* mGrid{};
		float mNextEnemy{};
	};

}
#endif // !APPLICATION_4
