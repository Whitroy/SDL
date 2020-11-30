#include"Chapter2( Object Model,Sprites)/Application2.h"
#include"GameEssentials/SpriteComponent.h"
#include"GameEssentials/CircleComponent.h"
#include"GameEssentials/InputComponent.h"
#include "BattleShip.h"
#include"Laser.h"
#include "Asteroid.h"
namespace SDLChapter3 
{
	BattleShip::BattleShip(Application2* game) :
		Actor{ game }, mIsInvinsible{ false }, mInvinsibleTime{ 2.0f }
	{
		mSc = new SpriteComponent(this, 150);
		mSc->SetTexture(game->GetTexture("Assests/Ship.png"));

		mIc = new InputComponent(this);
		mIc->SetForwardKey(SDL_SCANCODE_W);
		mIc->SetBackKey(SDL_SCANCODE_S);
		mIc->SetClockwiseKey(SDL_SCANCODE_A);
		mIc->SetCounterClockwiseKey(SDL_SCANCODE_D);
		mIc->SetMaxForwardSpeed(500000.0f);
		mIc->SetMass(40.0f);
		mIc->SetMaxAngularSpeed(Math::TwoPi);

		mCc = new CircleComponent(this);
		mCc->SetRadius(30.0f);
	}

	void BattleShip::UpdateActor(float deltaTime)
	{
		if (!mIsInvinsible)
		{
			mLaserCoolDown -= deltaTime;
			if (mIc->GetVelocity() != Vector2::Zero  || mIc->GetAngularSpeed() != 0.0f)
			{
				mSc->SetTexture(GetGame()->GetTexture("Assests/ShipWithThrust.png"));
			}
			else
			{
				mSc->SetTexture(GetGame()->GetTexture("Assests/Ship.png"));
			}

			for (auto ast : static_cast<Application2*>(GetGame())->GetAsteroids())
			{
				if (Intersect(*(ast->GetCircle()), *mCc))
				{
					mIsInvinsible = true;
					SetPosition(Vector2{512.0f,310.0f});
					break;
				}
			}
		}
		else
		{
			mInvinsibleTime -= deltaTime;
			mSc->SetTexture(nullptr);
			if (mInvinsibleTime <= 0.0f)
			{
				mInvinsibleTime = 2.0f;
				mIsInvinsible = false;
			}
		}
	}

	void BattleShip::ActorInput(const uint8_t* keyState)
	{
		if (!mIsInvinsible && mLaserCoolDown <= 0.0f && keyState[SDL_SCANCODE_SPACE])
		{
			Laser* laser = new Laser(static_cast<Application2*>(GetGame()));
			laser->SetPosition(GetPosition());
			laser->SetRotation(GetRotation());
			laser->Move(GetForward());

			// Reset laser cooldown (half second)
			mLaserCoolDown = 0.5f;
		}
	}
}
