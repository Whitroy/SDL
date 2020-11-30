#include "Application1.h"
#include<cmath>

namespace SDLChapter1
{
	Application1::Application1(int width, int height) :mWindow{ nullptr }, mIsRunning{ true }, mRenderer{ nullptr },
		Player1{ {-500,0},0 }, mBallPos{ 0,0 }, mWidth{ width }, mHeight{ height }, mTicksCount{ 0 },
		mthickness{ 15 }, mBallVel{ -200.0f,235.0f }, Player2{ {480,0},0 }
	{
	}

	bool Application1::Intialize()
	{
		int sdlResult = SDL_Init(SDL_INIT_VIDEO);
		if (sdlResult != 0)
		{
			SDL_Log("Unable to intialize SDL: %s", SDL_GetError);
			return false;
		}

		mWindow = SDL_CreateWindow("SDL Learning", 100, 100, mWidth, mHeight, 0);

		if (!mWindow)
		{
			SDL_Log("Failed to create window: %s", SDL_GetError);
			return false;
		}

		mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

		if (!mRenderer)
		{
			SDL_Log("Failed to create Renderer: %s", SDL_GetError);
			return false;
		}
		return true;
	}

	void Application1::ProcessInput()
	{
		SDL_Event event;

		//while there are still events in the queue 
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				mIsRunning = false;
				break;
			default:
				break;
			}
		}

		//Get State of Keyboard

		const Uint8* state = SDL_GetKeyboardState(nullptr);

		Player1.mPaddleDir = 0;
		Player2.mPaddleDir = 0;

		//if escape is pressed, end loop
		if (state[SDL_SCANCODE_ESCAPE])
		{
			mIsRunning = false;
		}

		if (state[SDL_SCANCODE_W])
		{
			Player1.mPaddleDir -= 1;
		}

		if (state[SDL_SCANCODE_S])
		{
			Player1.mPaddleDir += 1;
		}

		if (state[SDL_SCANCODE_I])
		{
			Player2.mPaddleDir -= 1;
		}

		if (state[SDL_SCANCODE_J])
		{
			Player2.mPaddleDir += 1;
		}
	}

	void Application1::UpdateGame()
	{
		while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16));
		float deltaTime = static_cast<float>((SDL_GetTicks() - mTicksCount) / 1000);
		mTicksCount = SDL_GetTicks();

		if (deltaTime > .05f)
			deltaTime = .05f;

		//player1Update
		if (Player1.mPaddleDir != 0)
		{
			Player1.mPaddlePos.y += Player1.mPaddleDir * 500.0f *deltaTime;
			if (Player1.mPaddlePos.y > (mHeight / 2- mthickness*4))
			{
				Player1.mPaddlePos.y = static_cast<float> (mHeight / 2 - mthickness*4);
			}

			if (Player1.mPaddlePos.y < mthickness*3 - mHeight/2)
			{
				Player1.mPaddlePos.y = static_cast<float> (mthickness * 3 - mHeight / 2);
			}
		}

		//Player2Update
		if (Player2.mPaddleDir != 0)
		{
			Player2.mPaddlePos.y += Player2.mPaddleDir * 500.0f * deltaTime;
			if (Player2.mPaddlePos.y > (mHeight / 2 - mthickness * 4))
			{
				Player2.mPaddlePos.y = static_cast<float> (mHeight / 2 - mthickness * 4);
			}

			if (Player2.mPaddlePos.y < mthickness * 3 - mHeight / 2)
			{
				Player2.mPaddlePos.y = static_cast<float> ( mthickness * 3 - mHeight / 2);
			}
		}


		//BallUpdate
		mBallPos.x += mBallVel.x * deltaTime;
		mBallPos.y += mBallVel.y * deltaTime;

		if (mBallPos.y < mthickness*2 - mHeight / 2 ||  mBallPos.y > mHeight / 2 - mthickness*2)
		{
			mBallVel.y *= -1;
		}

		if (((std::abs(mBallPos.x - Player1.mPaddlePos.x) < mthickness) 
			&&(std::abs( mBallPos.y - Player1.mPaddlePos.y) < mthickness*2.5f))
			|| ((std::abs(mBallPos.x - Player2.mPaddlePos.x) < mthickness)
				&& (std::abs(mBallPos.y - Player2.mPaddlePos.y) < mthickness * 2.5f)))
		{
			mBallVel.x *= -1;
		}	
	}

	void Application1::GenerateOutput()
	{
		SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);

		//clear the back buffer
		SDL_RenderClear(mRenderer);

		//Drawing Graphics
		SDL_SetRenderDrawColor(mRenderer, 178, 34, 34, 255);

		//Wall
		SDL_Rect wall{ 0,0,1024,mthickness };
		SDL_RenderFillRect(mRenderer, &wall);
		wall = { 0,720 - mthickness,1024,15 };
		SDL_RenderFillRect(mRenderer, &wall);

		//Ball
		SDL_SetRenderDrawColor(mRenderer, 255, 255, 255, 255);
		SDL_Rect ball{
			static_cast<int>(mBallPos.x + mWidth / 2),
			static_cast<int>(mBallPos.y) + mHeight / 2,
			mthickness,mthickness
		};
		SDL_RenderFillRect(mRenderer, &ball);

		//paddle1
		SDL_Rect paddle1{
			static_cast<int>(Player1.mPaddlePos.x + mWidth / 2),
			static_cast<int>(Player1.mPaddlePos.y + mHeight / 2) - mthickness * 2,
			mthickness,mthickness * 5
		};
		SDL_RenderFillRect(mRenderer, &paddle1);

		//paddle2
		SDL_Rect paddle2{
			static_cast<int>(Player2.mPaddlePos.x +  mWidth / 2),
			static_cast<int>(Player2.mPaddlePos.y + mHeight / 2) - mthickness * 2,
			mthickness,mthickness * 5
		};
		SDL_RenderFillRect(mRenderer, &paddle2);
		//swaping front and back buffer
		SDL_RenderPresent(mRenderer);
	}

	void Application1::RunLoop()
	{
		while (mIsRunning)
		{
			ProcessInput();

			UpdateGame();

			GenerateOutput();
		}
	}

	void Application1::Shutdown()
	{
		SDL_DestroyRenderer(mRenderer);
		SDL_DestroyWindow(mWindow);
		SDL_Quit();
	}
}