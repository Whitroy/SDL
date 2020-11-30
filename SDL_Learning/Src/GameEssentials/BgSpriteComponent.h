#ifndef BG_SPRITE_COMPONENT_H
#define BG_SPRITE_COMPONENT_H
#include "SpriteComponent.h"
#include<vector>
#include"Math/Math.h"
class BGSpriteComponent : public SpriteComponent
{
public:
	BGSpriteComponent(class Actor* owner, int drawOrder = 10);

	void Update(float deltaTime) override;

	void Draw(SDL_Renderer* renderer) override;
	void SetBgTextures(const std::vector<SDL_Texture*> textures);

	void SetScreenSize(const Vector2& size) { mScreenSize = size; };

	void SetScrollSpeed(float speed) { mScrollSpeed = speed; }

	float GetScrollSpeed() const { return mScrollSpeed; };

private:
	Vector2 mScreenSize{};
	float mScrollSpeed{};

	struct BGTexture
	{
		SDL_Texture* mTexture{};
		Vector2 mOffset{};
	};

	std::vector<BGTexture> mBGTextures;
};

#endif