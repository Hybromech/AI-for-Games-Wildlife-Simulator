#pragma once
#include "State.h"

///State Machine manages and manipulates states.
/**
*/
class StateMachine
{
public: 
	StateMachine();
	~StateMachine();
	
	void update(Agent* agent,StateMachine* sm, float deltaTime);
	//!Changes the current state with newState.
	void requestStateChange(State* newState);
	//!Initialise the beginning state.
	void init_currentState(State* initState);
	//!Return the current state.
	State* getCurrentState();
	//!Return the Previous state.
	State* getPrevState();

	private:
	//!Current state the statemachine is proccesing.
	State* currentState;
	//!A reference to the previous state.
	State* prevState;
	//!A variable to store the next requested state.
	State* nextState;
};

