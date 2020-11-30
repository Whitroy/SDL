#ifndef SPRITECOMPONENT_H
#define SPRITECOMPONENT_H
#include "SDL.h"
#include "Component.h"

class SpriteComponent : public Component
{
protected:
	SDL_Texture* mTexture{};
	int mDrawOrder{};
	int mTexHeight{};
	int mTexWidth{};
public:
	SpriteComponent(class Actor* owner, int drawOrder = 50);
	~SpriteComponent();

	virtual void Draw(SDL_Renderer* renderer);

	virtual void SetTexture(SDL_Texture* texture);

	int GetDrawOrder() const { return mDrawOrder; };
	int GetTexHeight() const { return mTexHeight; };
	int GetTexWidth() const { return mTexWidth; };
};


#endif // !SPRITE_COMPONENT_H
