#pragma once
#include "State.h"
#include "Behaviour.h"
#include <iostream>

class ChasePlayerState : public State
{
	 void update(Agent* agent, StateMachine* sm, float deltaTime)override;
	 void init(Agent* agent)override;
	 void exit(Agent* agent)override;
};
	