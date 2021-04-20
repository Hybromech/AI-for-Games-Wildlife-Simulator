#pragma once
#include "Behaviour.h"

class KeyboardBehaviour : public Behaviour
{
public:
		KeyboardBehaviour();
		~KeyboardBehaviour();
		virtual bool Update(Agent*, float deltatime);
private:
	float m_speed = 500.0f;
};