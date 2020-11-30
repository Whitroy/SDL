#ifndef GAME_H
#define GAME_H

#define SDL_MAIN_HANDLED

#include"SDL.h"
#include<unordered_map>
#include"Actor.h"
#include"SpriteComponent.h"

class Game
{
protected:
	SDL_Window* mWindow{};
	SDL_Renderer* mRenderer{};

	int mWidth{};
	int mHeight{};

	double mTicksCount{};
	bool mIsRunning{};
	bool mUpdatingActors{};

	std::vector<class Actor*> mActors{};
	std::vector<class Actor*> mPendingActors{};

	std::unordered_map<std::string, SDL_Texture*> mTextures;
	std::vector<class SpriteComponent*> mSprites{};

public:

	Game(int width, int height);
	bool Intialize();
	void Shutdown();
	void RunLoop() ;

	void AddActor(class Actor* actor);
	void RemoveActor(Actor* actor);

	void AddSprite(class SpriteComponent* sprite);
	void RemoveSprite(class SpriteComponent* sprite);

	SDL_Texture* GetTexture(const std::string& fileName);

protected:
	void ProcessInput();
	void GenerateOutput();
	void UpdateGame();
	virtual void LoadData() = 0;
	SDL_Texture* LoadTexture(const char* file);
	void UnLoadData();
};

#endif // !GAME_H
