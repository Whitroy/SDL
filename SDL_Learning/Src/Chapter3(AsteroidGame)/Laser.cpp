#include"Chapter2( Object Model,Sprites)/Application2.h"
#include"GameEssentials/SpriteComponent.h"
#include"GameEssentials/MoveComponent.h"
#include"GameEssentials/CircleComponent.h"
#include "Laser.h"
#include"Asteroid.h"

namespace SDLChapter3
{
	Laser::Laser(Application2* game)
		: ::Actor{ game }, mSpeed{ 100000.0f }
	{
		mDeathTimer = 1.0f;
		SpriteComponent* sc = new SpriteComponent(this,10);
		sc->SetTexture(game->GetTexture("Assests/Laser2.png"));
		
		// Create a circle component (for collision)
		mCircle = new CircleComponent(this);
		mCircle->SetRadius(11.0f);
	}

	void Laser::Move(const Vector2& fwd)
	{
		// Create a move component, and set a forward speed
		MoveComponent* mc = new MoveComponent(this);
		mc->AddForce(fwd * mSpeed);
		mc->SetMass(5.0f);
	}

	void Laser::UpdateActor(float deltaTime)
	{
		// If we run out of time, laser is dead
		mDeathTimer -= deltaTime;
		if (mDeathTimer <= 0.0f)
		{
			SetState(State::EDead);
		}
		else
		{
			// Do we intersect with an asteroid?
			for (auto ast : static_cast<Application2*>(GetGame())->GetAsteroids())
			{
				if (Intersect(*mCircle, *(ast->GetCircle())))
				{
					SetState(State::EDead);
					ast->SetState(State::EDead);
					break;
				}
			}
		}
	}
}
