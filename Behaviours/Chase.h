#pragma once
#include "Behaviour.h"

class Behaviour;
class Chase : public Behaviour
{
private:
	const Agent* m_target;//does not need to be a shared pointer.
	float m_speed;
public:
	Chase(const Agent* target, float speed);
	~Chase();
	  bool Update(Agent*, float deltatime);
};