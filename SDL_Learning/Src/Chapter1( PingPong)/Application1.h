#ifndef APPLICATION1_H
#define  APPLICATION1_H
#define SDL_MAIN_HANDLED
#include<SDL.h>
#include"GameMath.h"

namespace SDLChapter1
{
	struct Paddle
	{
		GameMath::Vector2 mPaddlePos{};
		int mPaddleDir;
	};

	class Application1
	{
	private:
		//Fields
		SDL_Window* mWindow{};
		SDL_Renderer* mRenderer{};

		Paddle Player1{};
		Paddle Player2{};

		GameMath::Vector2 mBallPos{};
		bool mIsRunning{};

		int mWidth{};
		int mHeight{};

		double mTicksCount;

		int mthickness;	

		GameMath::Vector2 mBallVel{};

	private:
		//Functions
		void ProcessInput();

		void UpdateGame();

		void GenerateOutput();

	public:
		Application1(int width, int height);

		//Intialize the game
		bool Intialize();

		//Game Loop
		void RunLoop();

		//Shutdown
		void Shutdown();
	};
}

#endif
