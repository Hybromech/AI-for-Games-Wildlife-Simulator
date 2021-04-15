#include "StateMachine.h"
#include "ChasePlayerState.h"

StateMachine::StateMachine()
{
	currentState = new ChasePlayerState();
}
StateMachine::~StateMachine() {} //con

void StateMachine::update(Agent* agent, StateMachine* sm)
{
	StateMachine::currentState->update(agent,sm);

	if (nextState != nullptr)//if there is a next state
	{
		currentState->exit(agent);																																										
		nextState->init(agent);
		prevState = currentState;
		currentState = nextState;
		nextState = nullptr;
	}
}

void StateMachine::requestStateChange(Agent*,State* newState)
{
	nextState = newState;
}

State* StateMachine::getCurrentState()
{
	return  StateMachine::currentState; 
}
State* StateMachine::getPrevState()
{
	return  StateMachine::prevState;
}