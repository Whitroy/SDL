#ifndef GRID_H
#define GRID_H
#include"GameEssentials/Actor.h"
#include<vector>
#include"Tile.h"
namespace SDLChapter4
{
	class Grid :public Actor
	{
	private:
		void SelectTile(size_t row, size_t col);

		// Update textures for tiles on path
		void UpdatePathTiles(class Tile* start);

		class Tile* mSelectedTile{};

		//2D vector of tiles in grid
		std::vector<std::vector<class Tile*>> mTiles{};

		//Time until next ene,y
		float mNextEnemy{};

		const size_t NumRows{ 7 };
		const size_t NumCols{ 16 };

		const float StartY{ 192.0f };
		const float TileSize { 64.0f };

		const float EnemyTime{ 1.5f };

	public:
		Grid(class Application4* game);

		//handle a mouse click at th x/y screen locations
		void ProcessClick(int x, int y);

		//A* search
		bool FindPath(class Tile* start, class Tile* goal);

		//try to build tower
		void BuildTower();

		Tile* GetStartTile();
		Tile* GetEndTile();

		void UpdateActor(float deltaTime) override;
	};
}
#endif // !GRID_H
