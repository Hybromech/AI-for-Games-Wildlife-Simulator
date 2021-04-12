#pragma once
#include "Agent.h"
#include "StateMachine.h"

class State
{
	public : virtual void update(Agent* agent, StateMachine sm) = 0;
	virtual void init(Agent* agent) = 0;
	virtual void exit(Agent* agent) = 0;
};


