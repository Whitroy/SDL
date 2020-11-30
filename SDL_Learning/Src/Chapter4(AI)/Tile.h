#ifndef TILE_H
#define TILE_H
#include"GameEssentials/Actor.h"
#include<vector>
namespace SDLChapter4
{
	class Tile: public Actor
	{
	public:
		friend class Grid;
		enum class TileState
		{
			EDefault,
			EPath,
			EStart,
			EBase
		};

		Tile(class Application4* game);

		void SetTileState(TileState state);
		TileState GetTileState() const { return mTileState; }
		void ToggleSelect();
		const Tile* GetParent() const { return mParent; }

	private:
		//for pathFinding
		std::vector<Tile*> mAdjacent{};
		Tile* mParent{};
		float f{};
		float g{};
		float h{};
		bool mInOpenSet{};
		bool mInClosedSet{};
		bool mBlocked{};

		void UpdateTexture();
		class SpriteComponent* mSprite{};
		TileState mTileState{};
		bool mSelected{};
	};
}
#endif // !TILE_H
