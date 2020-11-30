#include"Game.h"
#include "Component.h"

Actor::Actor(Game* game) :
	mState{ State::EActive }, mPosition{ Vector2{0.0f,0.0f} },
	mScale{ 1.0f }, mRotation{ 0.0f }, mGame{ game }
{
	mGame->AddActor(this);
}

Actor::~Actor()
{
	mGame->RemoveActor(this);

	while (!mComponents.empty())
	{
		delete mComponents.back();
	}
}

void Actor::Update(float deltaTime)
{
	if (mState == State::EActive)
	{
		UpdateComponents(deltaTime);
		UpdateActor(deltaTime);
	}
}

void Actor::UpdateComponents(float deltaTime)
{
	for (auto comp : mComponents)
	{
		comp->Update(deltaTime);
	}
}

void Actor::UpdateActor(float deltaTime)
{
}

void Actor::AddComponent(Component* component)
{
	int myOrder = component->GetUpdateOrder();
	auto iter = mComponents.begin();

	for (;
		iter != mComponents.end();
		++iter)
	{
		if (myOrder < (*iter)->GetUpdateOrder())
		{
			break;
		}
	}

	mComponents.insert(iter, component);
}

void Actor::RemoveComponent(Component* component)
{
	bool flag{ false };
	auto iter = mComponents.begin();
	for (; iter != mComponents.end(); iter++)
	{
		if (*iter == component)
		{
			flag = true;
			break;
		}
	}
	mComponents.erase(iter);
}

void Actor::ProcessInput(const uint8_t* keyState)
{
	if (mState == State::EActive)
	{
		for (auto comp : mComponents)
		{
			comp->ProcessInput(keyState);
		}
		ActorInput(keyState);
	}
}

void Actor::ActorInput(const uint8_t* keyState)
{
}

