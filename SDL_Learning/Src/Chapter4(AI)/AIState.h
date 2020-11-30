#ifndef AI_STATE_H
#define AI_STATE_H
#include "AIComponent.h"
namespace SDLChapter4
{
	class AIState
	{
	protected:
		class AIComponent* mOwner{};
	public:
		AIState(class AIComponent* owner) :
			mOwner{ owner } {}

		virtual void Update(float deltaTime) = 0;
		virtual void OnEnter() = 0;
		virtual void OnExit() = 0;

		virtual const char* GetName() const = 0;
	};

	class AIPatrol :public AIState
	{
	public:
		AIPatrol(class AIComponent* owner);

		void Update(float deltaTime) override;
		void OnEnter() override;
		void OnExit() override;

		const char* GetName() const override
		{
			return "Patrol";
		}
	};

	class AIDeath : public AIState
	{
	public:
		AIDeath(class AIComponent* owner)
			:AIState(owner)
		{ }

		void Update(float deltaTime) override;
		void OnEnter() override;
		void OnExit() override;

		const char* GetName() const override
		{
			return "Death";
		}
	};

	class AIAttack : public AIState
	{
	public:
		AIAttack(class AIComponent* owner)
			:AIState(owner)
		{ }

		void Update(float deltaTime) override;
		void OnEnter() override;
		void OnExit() override;

		const char* GetName() const override
		{
			return "Attack";
		}
	};

}

#endif // !AI_STATE_H
