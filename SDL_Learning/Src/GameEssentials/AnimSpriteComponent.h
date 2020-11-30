#ifndef ANIM_SPRITE_COMPONENT_H
#define ANIM_SPRITE_COMPONENT_H
#include "SpriteComponent.h"
#include<vector>
class AnimSpriteComponent : public SpriteComponent
{
private:
	float mAnimFPS{};
	std::vector<SDL_Texture*> mAnimTextures{};
	float mCurrFrame{};

public:
	AnimSpriteComponent(class Actor* owner, int drawOrder = 100);

	void Update(float deltaTime) override;

	void SetAnimTextures(const std::vector<SDL_Texture*>& textures);

	// Set/get the animation FPS
	float GetAnimFPS() const { return mAnimFPS; }
	void SetAnimFPS(float fps) { mAnimFPS = fps; }
};

#endif 
