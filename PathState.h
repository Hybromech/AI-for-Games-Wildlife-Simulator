#pragma once
#include "State.h"
class Behaviour;
class Agent;

//class state;
class PathState : public State
{
	void update(Agent* agent, StateMachine* sm, float deltaTime)override;
	void init(Agent* agent)override;
	void exit(Agent* agent)override;
};