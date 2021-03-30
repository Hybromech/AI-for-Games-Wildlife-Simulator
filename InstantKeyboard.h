#pragma once

#include "Behaviour.h"

class InstantKeyboard : public Behaviour
{
	public:
	InstantKeyboard(float s);
	~InstantKeyboard();
	virtual void Update(Agent*, float deltatime);
private:
	float m_speed = 500.0f;
};
