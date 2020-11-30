#include "GameEssentials/Actor.h"
#include "AIComponent.h"
#include"AIState.h"
namespace SDLChapter4
{
	AIComponent::AIComponent(Actor* owner)
		:Component{ owner }
	{
	}

	void AIComponent::Update(float deltaTime)
	{
		if(mCurrentState)
			mCurrentState->Update(deltaTime);
	}

	void AIComponent::ChangeState(const std::string& name)
	{
		if (mCurrentState)
			mCurrentState->OnExit();

		auto iter = mStatesMap.find(name);

		if (iter != mStatesMap.end())
		{
			mCurrentState = iter->second;
			mCurrentState->OnEnter();
		}
		else
		{
			SDL_Log("Could not find AIState %s in state map", name);
			mCurrentState = nullptr;
		}
	}

	void AIComponent::RegisterState(AIState* state)
	{
		mStatesMap.emplace(state->GetName(), state);
	}
}
