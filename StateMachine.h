#pragma once
#include "State.h"

class StateMachine
{
public: 
	StateMachine();
	~StateMachine();
	
	void update(Agent* agent,StateMachine* sm, float deltaTime);
	void requestStateChange(Agent* agent, State* newState);

	State* getCurrentState();
	State* getPrevState();

	private:
	State* currentState;
	State* prevState;
	State* nextState;
};

