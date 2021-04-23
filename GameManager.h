#pragma once
#include<Vector>
class Agent;
class GameManager
{
		public :
		//std::vector<Agent*> agents;
		std::vector<Agent*> agents;
		bool DetectAgent(Agent*);
		GameManager(std::vector<Agent*> passed_agents);
		~GameManager();
		
};