#include "WanderState.h"


void WanderState::update(Agent* agent, StateMachine* sm, float deltaTime)
	{
		std::cout << "Wandering";
		agent->m_behaviours[0]->Update(agent, deltaTime);
		//if (GameManager::DetectAgent(agent) == true)//Query detection
		//{
		//	std::cout << "Changing state to chase" << std::endl;
		//	//sm->requestStateChange(agent,(State*)agent->chaseState);//Cast into State
		//}
	}

	void WanderState::init(Agent* agent)
	{
	}

	void WanderState::exit(Agent* agent)
	{
	}

