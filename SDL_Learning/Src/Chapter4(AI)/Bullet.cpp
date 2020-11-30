#include"GameEssentials/MoveComponent.h"
#include"GameEssentials/CircleComponent.h"
#include"Application4.h"
#include"Bullet.h"
#include"Enemy.h"
#include"Tower.h"
namespace SDLChapter4
{
	Bullet::Bullet(class Application4* game)
		:Actor{ game }

	{
		SpriteComponent* sc = new SpriteComponent(this);
		sc->SetTexture(game->GetTexture("Assests/Projectile.png"));

		MoveComponent* mc = new MoveComponent(this);
		mc->AddForce(mTower->GetForward() * 1000000.0f);
		mc->SetMass(20.0f);

		mCircle = new CircleComponent(this);
		mCircle->SetRadius(5.0f);

		mLiveTime = 1.0f;
	}

	void Bullet::UpdateActor(float deltaTime)
	{
		Actor::UpdateActor(deltaTime);

		// Check for collision vs enemies
		for (Enemy* e : static_cast<Application4*>(GetGame())->GetEnemies())
		{
			if (Intersect(*mCircle, *(e->GetCircle())))
			{
				// We both die on collision
				e->SetState(State::EDead);
				SetState(State::EDead);
				break;
			}
		}

		mLiveTime -= deltaTime;
		if (mLiveTime <= 0.0f)
		{
			// Time limit hit, die
			SetState(State::EDead);
		}
	}
}