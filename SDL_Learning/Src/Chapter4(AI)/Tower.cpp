#include"Application4.h"
#include"GameEssentials/MoveComponent.h"
#include"GameEssentials/CircleComponent.h"
#include"Enemy.h"
#include"Tower.h"
#include"Bullet.h"

namespace SDLChapter4
{
	Tower::Tower(Application4* game)
		:Actor{ game }, mNextAttack{ false }
	{
		SpriteComponent* sc = new SpriteComponent(this, 200);
		sc->SetTexture(game->GetTexture("Assests/Tower.png"));

		mMove = new MoveComponent(this);
		//mMove->SetAngularSpeed(Math::Pi);

		mNextAttack = AttackTime;
	}

	void Tower::UpdateActor(float deltaTime)
	{
		Actor::UpdateActor(deltaTime);

		mNextAttack -= deltaTime;
		if (mNextAttack <= 0.0f)
		{
			Enemy* e = static_cast<Application4*>(GetGame())->GetNearestEnemy(GetPosition());
			if (e != nullptr)
			{
				// Vector from me to enemy
				Vector2 dir = e->GetPosition() - GetPosition();
				float dist = dir.Length();
				if (dist < AttackRange)
				{
					// Rotate to face enemy
					SetRotation(Math::Atan2(-dir.y, dir.x));
					// Spawn bullet at tower position facing enemy
					Bullet* b = new Bullet(static_cast<Application4*>(GetGame()));
					b->SetPosition(GetPosition());
					b->SetRotation(GetRotation());
					b->mTower = this;
				}
			}
			mNextAttack += AttackTime;
		}
	}
}