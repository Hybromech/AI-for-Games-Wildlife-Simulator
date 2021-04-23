#include "StateMachine.h"


StateMachine::StateMachine()
{
	//currentState = new WanderState();
}
StateMachine::~StateMachine() {} //con

void StateMachine::update(Agent* agent, StateMachine* sm, float deltaTime)
{
	if (nextState != nullptr)//if there is a next state
	{
		currentState->exit(agent);																																									
		nextState->init(agent);
		prevState = currentState;
		currentState = nextState;
		nextState = nullptr;
	}
	StateMachine::currentState->update(agent, sm, deltaTime);
}

void StateMachine::requestStateChange(State* newState)
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

void StateMachine::init_currentState(State* initState)
{
	currentState = initState;
}