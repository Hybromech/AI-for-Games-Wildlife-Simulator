#pragma once
#include "State.h"

class StateMachine
{
public: 
	StateMachine();
	~StateMachine();
	
	void update(Agent* agent,StateMachine* sm, float deltaTime);
	void requestStateChange(State* newState);
	void init_currentState(State* initState);

	State* getCurrentState();
	State* getPrevState();

	private:
	State* currentState;
	State* prevState;
	State* nextState;
};

