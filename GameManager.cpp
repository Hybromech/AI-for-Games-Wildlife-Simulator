#include "GameManager.h"
#include "Agent.h"
#include "iostream"

GameManager::GameManager(std::vector<Agent*> passed_agents)
{
	agents = passed_agents;//?
}

GameManager::~GameManager() {};

bool GameManager::DetectAgent(Agent* calling_agent)
{
	std::cout << "Updated Detect Agent!" << std::endl;
	for (auto element : agents)
	{
		if (element->ID != calling_agent->ID);
		{
			std::cout << "DetectAgent: Distance" << glm::distance(calling_agent->GetPosition(), element->GetPosition());
			if (glm::distance(calling_agent->GetPosition(), element->GetPosition()) < 30)
			{
				std::cout << "DetectAgent: Agent in range!" << std::endl;
				return true;
			}
			else return false;
		}
	}
	//Work out the distance to the target and see if it is in range.
	
}