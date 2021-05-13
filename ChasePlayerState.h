#pragma once
#include "State.h"
#include "Behaviour.h"
#include <iostream>
///State associated with chasing.
/**
*/
class ChasePlayerState : public State
{
	 //!Updates the basic logic.
	 void update(Agent* agent, StateMachine* sm, float deltaTime)override;
	 //!Initialisation.
	 void init(Agent* agent)override;
	 //!Execute on exit.
	 void exit(Agent* agent)override;
};
	