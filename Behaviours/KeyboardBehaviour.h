#pragma once
#include "Behaviour.h"
///Handles keyboard input.
/**
*/
class KeyboardBehaviour : public Behaviour
{
public:
		KeyboardBehaviour();
		~KeyboardBehaviour();
		virtual bool Update(Agent*, float deltatime);
private:
	//!The speed the agent will move
	float m_speed = 500.0f;
};