#include"Asteroid.h"
#include"Math/Math.h"
#include"Chapter2( Object Model,Sprites)/Application2.h"
#include"GameEssentials/SpriteComponent.h"
#include"Math/Random.h"
#include"GameEssentials/MoveComponent.h"
#include"GameEssentials/CircleComponent.h"

namespace SDLChapter3
{

	int Asteroid::IDGenerator = 0;

	Asteroid::Asteroid(Application2* game)
		:Actor{ game }
	{
		mId = IDGenerator++;
		Vector2 randPos = Random::GetVector(Vector2::Zero, Vector2(1024.0f, 720.0f));
		SetScale(1.0f);
		SetPosition(randPos);
		SetRotation(Random::GetFloatRange(0.0f, Math::TwoPi));

		SpriteComponent* sc = new SpriteComponent(this);
		sc->SetTexture(game->GetTexture("Assests/Asteroid.png"));

		MoveComponent* mc = new MoveComponent(this);
		mc->AddForce(Vector2{ Random::GetFloatRange(-100000.0f, 100000.0f), Random::GetFloatRange(-100000.0f, 100000.0f) });
		mc->SetMass(40.0f);

		mCircle = new CircleComponent(this);
		mCircle->SetRadius(40.0f);

		game->AddAsteroid(this);
	}

	Asteroid::~Asteroid()
	{
		static_cast<Application2*>(GetGame())->RemoveAsteroid(this);
	}
}