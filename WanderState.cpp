#include "WanderState.h"
#include "GameManager.h"
#include "StateMachine.h"
#include "Agent.h"


void WanderState::update(Agent* agent, StateMachine* sm, float deltaTime)
	{
		agent->m_behaviours[0]->Update(agent, deltaTime);
		std::cout << "Wandering" << std::endl;
		std::cout << "Current_state" << sm->getCurrentState() << std::endl;
		std::cout << "Agent ID is" << agent->ID << std::endl;

		if (agent->gameManager->DetectAgent(agent) == true)//Query detection
		{
			std::cout << "Detected target! Changing state to chase" << std::endl;
			sm->requestStateChange(agent->chaseState);//does not change state
		}
	}

	void WanderState::init(Agent* agent)
	{
	}

	void WanderState::exit(Agent* agent)
	{
	}

