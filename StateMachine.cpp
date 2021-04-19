#include "StateMachine.h"
#include "ChasePlayerState.h"
#include "WanderState.cpp"

StateMachine::StateMachine()
{
	//currentState = new WanderState();
}
StateMachine::~StateMachine() {} //con

void StateMachine::update(Agent* agent, StateMachine* sm, float deltaTime)
{
	StateMachine::currentState->update(agent,sm, deltaTime);

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