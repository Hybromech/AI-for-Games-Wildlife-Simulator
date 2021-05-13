#pragma once
#include "State.h"
class Behaviour;
class Agent;

///A state associated with pathfinding.
/**
*/
class PathState : public State
{
	void update(Agent* agent, StateMachine* sm, float deltaTime)override;
	void init(Agent* agent)override;
	void exit(Agent* agent)override;
};