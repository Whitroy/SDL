#include "Game.h"
#include"Chapter4(AI)/Debug.h"
#include"sdl_image.h"
Game::Game(int width, int height):
    mWidth{ width }, mHeight{ height }, mWindow{ nullptr }, mRenderer{ nullptr },
    mTicksCount{ 0.0f }, mIsRunning{ false }, mUpdatingActors{ false }
{}


bool Game::Intialize()
{
	int sdlResult = SDL_Init(SDL_INIT_VIDEO);
	if (sdlResult != 0)
	{
		Log("Unable to Intialize SDL");
		return false;
	}

	mWindow = SDL_CreateWindow("SDL Learning", 100, 100, mWidth, mHeight, 0);

	if (!mWindow)
	{
		Log("Unable to Intialize Window!");
		return false;
	}

	mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	if (!mRenderer)
	{
		Log("Failed to Crate Window");
		return false;
	}

	if (IMG_Init(IMG_INIT_PNG) == 0)
	{
		Log("Failed to Intialize SDL Image");
		return false;
	}

	mTicksCount = SDL_GetTicks();
	mIsRunning = true;
	LoadData();
	return true;
}

void Game::Shutdown()
{
	UnLoadData();
	IMG_Quit();
	SDL_DestroyRenderer(mRenderer);
	SDL_DestroyWindow(mWindow);
	SDL_Quit();
}

void Game::RunLoop()
{
	while (mIsRunning)
	{
		ProcessInput();

		UpdateGame();

		GenerateOutput();
	}
}

void Game::AddActor(Actor* actor)
{
	if (mUpdatingActors)
		mActors.emplace_back(actor);
	else
		mPendingActors.emplace_back(actor);
}

void Game::RemoveActor(Actor* actor)
{
	auto iter = std::find(mPendingActors.begin(), mPendingActors.end(), actor);
	if (iter != mPendingActors.end())
	{
		std::iter_swap(iter, mPendingActors.end() - 1);
		mPendingActors.pop_back();
	}

	iter = std::find(mActors.begin(), mActors.end(), actor);
	if (iter != mActors.end())
	{
		std::iter_swap(iter, mActors.end() - 1);
		mActors.pop_back();
	}
}

void Game::AddSprite(SpriteComponent* sprite)
{
	int myDrawOrder = sprite->GetDrawOrder();
	auto iter = mSprites.begin();
	for (; iter != mSprites.end(); ++iter)
	{
		if (myDrawOrder < (*iter)->GetDrawOrder())
			break;
	}

	mSprites.insert(iter, sprite);
}

void Game::RemoveSprite(SpriteComponent* sprite)
{
	auto iter = std::find(mSprites.begin(), mSprites.end(), sprite);
	if (iter != mSprites.end())
		mSprites.erase(iter);
}


SDL_Texture* Game::GetTexture(const std::string& fileName)
{
    if (mTextures.find(fileName) != mTextures.end())
        return mTextures[fileName];
    return LoadTexture(fileName.c_str());
}

void Game::ProcessInput()
{
	SDL_Event event;

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

	const Uint8* state = SDL_GetKeyboardState(nullptr);
	if (state[SDL_SCANCODE_ESCAPE])
	{
		mIsRunning = false;
	}

	mUpdatingActors = true;
	for (auto actor : mActors)
	{
		actor->ProcessInput(state);
	}
	mUpdatingActors = true;
}

void Game::GenerateOutput()
{
	SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, 255);
	SDL_RenderClear(mRenderer);

	for (auto sprite : mSprites)
	{
		sprite->Draw(mRenderer);
	}

	SDL_RenderPresent(mRenderer);
}

void Game::UpdateGame()
{
	while (!SDL_TICKS_PASSED(SDL_GetTicks(), mTicksCount + 16));
	float deltaTime = (SDL_GetTicks() - mTicksCount) / 1000;
	mTicksCount = SDL_GetTicks();
	if (deltaTime > .05f)
		deltaTime = .05f;

	mUpdatingActors = true;
	//update actors
	for (auto actor : mActors)
	{
		actor->Update(deltaTime);
	}
	mUpdatingActors = false;

	for (auto pending : mPendingActors)
	{
		mActors.emplace_back(pending);
	}

	mPendingActors.clear();
	//deleting dead actors

	std::vector<Actor*> deadActors{};
	for (auto actor : mActors)
	{
		if (actor->GetState() == Actor::State::EDead)
			deadActors.emplace_back(actor);
	}

	for (auto actor : deadActors)
	{
		delete actor;
	}
}

SDL_Texture* Game::LoadTexture(const char* file)
{
	if (mTextures.find(file) != mTextures.end())
	{
		Log("Already Registered Texture : " << file);
		return nullptr;
	}
	SDL_Surface* LoadedImage = IMG_Load(file);
	if (!LoadedImage)
	{
		Log("Unable to Load Image File : " << file);
		return nullptr;
	}

	//converting sdlsurface to sdltexture for drawing
	SDL_Texture* Texture{ SDL_CreateTextureFromSurface(mRenderer,LoadedImage) };
	if (!Texture)
	{
		Log("Failed to convert surface to texture for " << file);
		return nullptr;
	}
	mTextures[file] = Texture;
	return Texture;
}

void Game::UnLoadData()
{
	while (!mActors.empty())
	{
		delete mActors.back();
	}

	for (auto i : mTextures)
	{
		SDL_DestroyTexture(i.second);
	}
	mTextures.clear();
}
