#include "Ship.h"
#include"GameEssentials/AnimSpriteComponent.h"
#include"Application2.h"
namespace SDLChapter3
{
	Ship::Ship(Application2* game):Actor{game}, mRightSpeed{0.0f},mDownSpeed{0.0f}
	{
		AnimSpriteComponent* animSpriteComp = new AnimSpriteComponent(this);
		std::vector<SDL_Texture*>  anims = {
			game->GetTexture("Assests/Ship01.png"),
			game->GetTexture("Assests/Ship02.png"),
			game->GetTexture("Assests/Ship03.png"),
			game->GetTexture("Assests/Ship04.png"),
		};
		animSpriteComp->SetTexture(anims[0]);
		animSpriteComp->SetAnimTextures(anims);
		animSpriteComp->SetAnimFPS(24);
	}

	void Ship::UpdateActor(float deltaTime)
	{
		Actor::UpdateActor(deltaTime);

		Vector2 pos = GetPosition();
		pos.x += mRightSpeed * deltaTime;
		pos.y += mDownSpeed * deltaTime;

		if (pos.x < 25.0f)
		{
			pos.x = 25.0f;
		}
		else if (pos.x > 500.0f)
		{
			pos.x = 500.0f;
		}

		if (pos.y < 25.0f)
		{
			pos.y = 25.0f;
		}
		else if (pos.y > 700.0f)
		{
			pos.y = 700.0f;
		}
		SetPosition(pos);
	}

	void Ship::ProcessKeyboard(const uint8_t* state)
	{
		mRightSpeed = 0.0f;
		mDownSpeed = 0.0f;

		if (state[SDL_SCANCODE_D])
			mRightSpeed += 250.0f;
		if (state[SDL_SCANCODE_A])
			mRightSpeed -= 250.0f;
		if (state[SDL_SCANCODE_S])
			mDownSpeed += 300.0f;
		if (state[SDL_SCANCODE_W])
			mDownSpeed -= 300.0f;
	}
}