#include "PathState.h"
#include "GameManager.h"
#include "StateMachine.h"
#include "Agent.h"


void PathState::update(Agent* agent, StateMachine* sm, float deltaTime)
{
	agent->m_behaviours[2]->Update(agent, deltaTime);
	std::cout << "Pathing" << std::endl;
	std::cout << "Current_state" << sm->getCurrentState() << std::endl;
	std::cout << "Agent ID is" << agent->ID << std::endl;

	if (agent->gameManager->DetectAgent(agent) == true)//Query detection
	{
		std::cout << "Detected target! Changing state to chase" << std::endl;
		sm->requestStateChange(agent->chaseState);//does not change state
	}
}

void PathState::init(Agent* agent)
{
}

void PathState::exit(Agent* agent)
{
}

