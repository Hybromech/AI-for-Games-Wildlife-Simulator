#include "ChasePlayerState.h"
#include <iostream>

void ChasePlayerState::update(Agent* agent, StateMachine* sm)
{
	//std::cout << "chasing player";
	//chase the target bug

	//If cannot see the target
	//change state to search

	//If within range of target
	//change state to attack
	
	agent->AddForce(glm::vec2{ 50,0 });
}

void ChasePlayerState::init(Agent* agent)
{
}

void ChasePlayerState::exit(Agent* agent)
{
}