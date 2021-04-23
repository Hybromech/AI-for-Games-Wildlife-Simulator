#include "WanderState.h"
#include "GameManager.h"
#include "StateMachine.h"
#include "Agent.h"


void WanderState::update(Agent* agent, StateMachine* sm, float deltaTime)
	{
		agent->m_behaviours[0]->Update(agent, deltaTime);
		std::cout << "Wandering";
		//sm->requestStateChange(agent->chaseState);//Cast into State
		if (agent->gameManager->DetectAgent(agent) == true)//Query detection
		{
			std::cout << "Changing state to chase" << std::endl;
			sm->requestStateChange(agent->chaseState);//Cast into State
		}
	
	}

	void WanderState::init(Agent* agent)
	{
	}

	void WanderState::exit(Agent* agent)
	{
	}

