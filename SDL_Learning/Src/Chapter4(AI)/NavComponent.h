#ifndef NAV_COMPONENT_H
#define NAV_COMPONENT_H
#include "GameEssentials/MoveComponent.h"

namespace SDLChapter4
{
	class NavComponent :public MoveComponent
	{
	private:
		const class Tile* mNextNode{};
	public:
		NavComponent(class Actor* owner);
		void TurnTo(const Vector2& pos);
		void Update(float deltaTime) override;
		void StartPath(const class Tile* start);
	};
}

#endif // !NAV_COMPONENT_H
