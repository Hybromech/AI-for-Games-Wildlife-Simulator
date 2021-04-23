#include "ChasePlayerState.h"
#include "Agent.h"


void ChasePlayerState::update(Agent* agent, StateMachine* sm, float deltaTime)
{
	//std::cout << "chasing player";
	//chase the target bug

	//If cannot see the target
	//change state to search

	//If within range of target
	//change state to attack
	
	agent->m_behaviours[1]->Update(agent, deltaTime);
	std::cout << "Chasing" << std::endl;
}

void ChasePlayerState::init(Agent* agent)
{
}

void ChasePlayerState::exit(Agent* agent)
{
}