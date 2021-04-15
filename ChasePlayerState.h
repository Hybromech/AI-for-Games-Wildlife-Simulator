#pragma once
#include "State.h"

class ChasePlayerState : public State
{
	 void update(Agent* agent, StateMachine* sm)override;
	 void init(Agent* agent)override;
	 void exit(Agent* agent)override;
};
	