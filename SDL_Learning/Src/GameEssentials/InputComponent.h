#ifndef INPUTCOMPONENT_H
#define INPUTCOMPONENT_H
#include"MoveComponent.h"
class InputComponent : public MoveComponent
{
private:
	// The maximum forward/angular speeds
	float mMaxForwardSpeed{};
	float mMaxAngularSpeed{};
	// Keys for forward/back movement
	int mForwardKey{};
	int mBackKey{};
	// Keys for angular movement
	int mClockwiseKey{};
	int mCounterClockwiseKey{};

public:
	InputComponent(Actor* Owner);
	void ProcessInput(const uint8_t* keystate) override;

	inline float GetMaxForwardSpeed() { return mMaxForwardSpeed; };
	inline float GetMaxAngularSpeed() { return mMaxAngularSpeed; };

	inline int GetForwardKey() const { return mForwardKey; }
	inline int GetBackKey() const { return mBackKey; }
	inline int GetClockwiseKey() const { return mClockwiseKey; }
	inline int GetCounterClockwiseKey() const { return mCounterClockwiseKey; }

	inline void SetMaxForwardSpeed(float speed) { mMaxForwardSpeed = speed; }
	inline void SetMaxAngularSpeed(float speed) { mMaxAngularSpeed = speed; }
	inline void SetForwardKey(int key) { mForwardKey = key; }
	inline void SetBackKey(int key) { mBackKey = key; }
	inline void SetClockwiseKey(int key) { mClockwiseKey = key; }
	inline void SetCounterClockwiseKey(int key) { mCounterClockwiseKey = key; }
};

#endif // !INPUTCOMPONENT_H
