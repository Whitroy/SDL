#include"GameEssentials/CircleComponent.h"
#include"NavComponent.h"
#include "Enemy.h"
#include"Chapter4(AI)/Application4.h"
#include "Grid.h"
#include "Tile.h"

namespace SDLChapter4
{
	Enemy::Enemy(Application4* game)
		:Actor{ game }
	{
		game->GetEnemies().emplace_back(this);

		SpriteComponent* sc = new SpriteComponent(this);
		sc->SetTexture(game->GetTexture("Assests/Airplane.png"));

		SetPosition(static_cast<Application4*>(GetGame())->GetGrid()->GetStartTile()->GetPosition());

		NavComponent* nc = new NavComponent(this);
		nc->AddForce(GetForward() * 1000000.0f);
		nc->SetMass(40.0f);
		nc->StartPath(static_cast<Application4*>(GetGame())->GetGrid()->GetStartTile());
		// Setup a circle for collision
		mCircle = new CircleComponent(this);
		mCircle->SetRadius(25.0f);
	}

	Enemy::~Enemy()
	{
		auto iter = std::find(static_cast<Application4*>(GetGame())->GetEnemies().begin(),
			static_cast<Application4*>(GetGame())->GetEnemies().end(),
			this);
		static_cast<Application4*>(GetGame())->GetEnemies().erase(iter);
	}

	void Enemy::UpdateActor(float deltaTime)
	{
		Actor::UpdateActor(deltaTime);

		// Am I near the end tile?
		Vector2 diff = GetPosition() - static_cast<Application4*>(GetGame())->GetGrid()->GetEndTile()->GetPosition();
		if (Math::NearZero(diff.Length(), 10.0f))
		{
			SetState(State::EDead);
		}
	}
}
