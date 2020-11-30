#ifndef COMPONENT_H
#define COMPONENT_H
#include"SDL.h"
class Component
{
protected:
	class Actor* mOwner;
	int mUpdateOrder;
public:
	Component(class Actor* owner, int updateOrder = 10);
	virtual ~Component();

	virtual void Update(float deltaTime);

	virtual void ProcessInput(const Uint8* keyState) {};

	int GetUpdateOrder() const { return mUpdateOrder; }
};

#endif // !COMPONENT_H
