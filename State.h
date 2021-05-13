#pragma once
class Agent;
class StateMachine;

///Base class for all states.
/**
*/
class State
{
	public:
	virtual void update(Agent* agent, StateMachine* sm, float deltaTime) = 0;//pure virtual fucntion
	virtual void init(Agent* agent) = 0;
	virtual void exit(Agent* agent) = 0;
};


