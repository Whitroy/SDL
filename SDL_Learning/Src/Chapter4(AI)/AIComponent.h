#ifndef AI_COMPONENT_H
#define AI_COMPONENT_H

#include<GameEssentials/Component.h>
#include<string>
#include<unordered_map>
namespace SDLChapter4
{
	class AIComponent : public Component
	{
	private:
		std::unordered_map<std::string, class AIState*> mStatesMap{};
		class AIState* mCurrentState{};
	public:
		AIComponent(class ::Actor* owner);

		void Update(float deltaTime) override;
		void ChangeState(const std::string& name);

		void RegisterState(class AIState* state);
	};
}
#endif