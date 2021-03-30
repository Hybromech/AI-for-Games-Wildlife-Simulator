#pragma once

#include "Behaviour.h"
class Chase : public Behaviour
{
private:
	const Agent* m_target;//does not need to be a shared pointer.
	float m_speed;
public:
	Chase(const Agent* target, float speed);
	~Chase();
	  void Update(Agent*, float deltatime);
};