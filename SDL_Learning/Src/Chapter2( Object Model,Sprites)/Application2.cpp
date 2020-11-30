#include"Application2.h"
#include"GameEssentials/BgSpriteComponent.h"
#include"Chapter3(AsteroidGame)/Asteroid.h"
#include"Chapter3(AsteroidGame)/BattleShip.h"
namespace SDLChapter3
{
	Application2::Application2(int width, int height)
		:Game{ width,height }
	{

	}

	void Application2::AddAsteroid(Asteroid* ast)
	{
		mAsteroids.emplace_back(ast);
	}

	void Application2::LoadData()
	{
		using namespace SDLChapter3;
		//Create player's ship
		mShip = new BattleShip(this);
		mShip->SetPosition(Vector2{ static_cast<float>(mWidth) / 2,static_cast<float>(mHeight) / 2 });
		mShip->SetScale(1.0f);
		mShip->SetRotation(Math::PiOver2);

		//background
		Actor* temp = new Actor(this);
		temp->SetPosition(Vector2{ static_cast<float>(mWidth)/2,static_cast<float>(mHeight)/2 });
		temp->SetScale(1.0f);

		//far background
		BGSpriteComponent* bg = new BGSpriteComponent(temp);
		bg->SetScreenSize(Vector2{ static_cast<float>(mWidth),static_cast<float>(mHeight) });
		std::vector<SDL_Texture*> bgTexture = {
			GetTexture("Assests/Farback01.png"),
			GetTexture("Assests/Farback02.png")
		};
		bg->SetTexture(bgTexture[0]);
		bg->SetBgTextures(bgTexture);
		bg->SetScrollSpeed(-100.0f);

		//closer background
		bg = new BGSpriteComponent(temp, 50);
		bg->SetScreenSize(Vector2{ static_cast<float>(mWidth),static_cast<float>(mHeight) });
		bgTexture = {
			GetTexture("Assests/Stars.png"),
			GetTexture("Assests/Stars.png")
		};

		bg->SetTexture(bgTexture[0]);
		bg->SetBgTextures(bgTexture);
		bg->SetScrollSpeed(-200.0f);

		const int numAsteroids = 20;
		for (int i = 0; i < numAsteroids; i++)
		{
			new SDLChapter3::Asteroid(this);
		}
	}

	void Application2::RemoveAsteroid(SDLChapter3::Asteroid* ast)
	{
		auto iter = std::find(mAsteroids.begin(), mAsteroids.end(), ast);
		if (iter != mAsteroids.end())
		{
			mAsteroids.erase(iter);
		}
	}
}