#include "StateMachine.h"

void StateMachine::update(Agent* agent, StateMachine sm)
{
	StateMachine::currentState->update(agent,sm);

	if (nextState != nullptr)
	{
		currentState->exit(agent);
		nextState->init(agent);
		prevState = currentState;
		currentState = nextState;
		nextState = nullptr;
	}
};

void StateMachine::requestStateChange(Agent*,State* newState)
{
	nextState = newState;
}