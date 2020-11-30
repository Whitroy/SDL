#include"AnimSpriteComponent.h"
AnimSpriteComponent::AnimSpriteComponent(Actor* owner, int drawOrder) :
	SpriteComponent{ owner,drawOrder }
{

}

void AnimSpriteComponent::Update(float deltaTime)
{
	SpriteComponent::Update(deltaTime);
	if (mAnimTextures.size() > 0)
	{
		mCurrFrame += mAnimFPS * deltaTime;
	}

	while (mCurrFrame >= mAnimTextures.size())
	{
		mCurrFrame -= mAnimTextures.size();
	}

	SetTexture(mAnimTextures[static_cast<int>(mCurrFrame)]);
}

void AnimSpriteComponent::SetAnimTextures(const std::vector<SDL_Texture*>& textures)
{
	for (auto tex : textures)
	{
		mAnimTextures.emplace_back(tex);
	}
}