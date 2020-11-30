#ifndef ACTOR_H
#define ACTOR_H

#include"Game.h"
#include "Math/Math.h"
#include<vector>

class Actor
{
public:
	enum class State
	{
		EActive,
		EPaused,
		EDead
	};

private:
	State mState{};

	Vector2 mPosition{};
	float mScale{};
	float mRotation{};

	std::vector<class Component*> mComponents{};

	class Game *mGame{};

public:
	Actor(Game* game);
	virtual ~Actor();

	void Update(float deltaTime);
	void UpdateComponents(float deltaTime);
	virtual void UpdateActor(float deltaTime);

	void AddComponent(class Component* component);
	void RemoveComponent(class Component* component);

	void ProcessInput(const uint8_t* keyState);
	virtual void ActorInput(const uint8_t* keyState);

	inline Vector2 GetForward() const { return Vector2(Math::Cos(mRotation), -Math::Sin(mRotation)); }
	inline State GetState() const { return mState; }
	inline Game* GetGame() const { return mGame; }
	inline Vector2 GetPosition() const { return mPosition; }
	inline float GetScale() const { return mScale; }
	inline float GetRotation() const { return mRotation; }
	inline void SetPosition(const Vector2& pos) { mPosition.x = pos.x; mPosition.y = pos.y; }
	inline void SetScale(const float scale) { mScale = scale; };
	inline void SetRotation(const float rot) { mRotation = rot; }
	inline void SetState(State state) { mState = state; }
};
#endif // !ACTOR_H
