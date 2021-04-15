#pragma once
#include "State.h"

class Agent;
class State;
class StateMachine
{
public: 
	StateMachine();
	~StateMachine();
	
	void update(Agent* agent,StateMachine* sm);
	void requestStateChange(Agent* agent, State* newState);

	State* getCurrentState();
	State* getPrevState();

	private:
	State* currentState;
	State* prevState;
	State* nextState;
};

