#pragma once
#include "Agent.h"
#include "StateMachine.h"
//#include "GameManager.h"
//#include "Behaviour.h"

class Agent;
class StateMachine;
//Abstract base class
class State
{
	public:
	virtual void update(Agent* agent, StateMachine* sm, float deltaTime) = 0;//pure virtual fucntion
	virtual void init(Agent* agent) = 0;
	virtual void exit(Agent* agent) = 0;
};


