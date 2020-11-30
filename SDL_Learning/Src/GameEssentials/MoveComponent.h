#ifndef MOVE_COMPONENT_H
#define MOVE_COMPONENT_H
#include"Component.h"
#include"Math/Math.h"
class MoveComponent : public Component
{
private:
	Vector2 mForce{};
	float mAngularSpeed{};
	Vector2 mVelocity{};
	float mMass{};
public:
	inline float GetAngularSpeed()const { return mAngularSpeed; };
	inline void SetAngularSpeed(const float speed) { mAngularSpeed = speed; };
	inline void AddForce(const Vector2& force) { mForce += force; }
	inline void SetMass(const float mass) { mMass = mass; }
	inline Vector2& GetVelocity() { return mVelocity; }
	inline void SetVelocity(const Vector2& vel) { mVelocity = vel; }
	//For moving Actor
	void Update(float deltaTime) override;

	MoveComponent(class Actor* owner, int updateOrder = 10);


};

#endif // !MOVE_COMPONENT_H
