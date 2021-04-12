#pragma once
#include "State.h"

class StateMachine {

	void update(Agent* agent,StateMachine sm);
	void requestStateChange(Agent* agent, State* newState);

	void getCurrentState();
	void getPrevState();

	State* currentState;
	State* prevState;
	State* nextState;
};

