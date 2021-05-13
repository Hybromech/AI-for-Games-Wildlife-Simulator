#pragma once
#include<Vector>
class Agent;
///Manages the game.
/**
	Provides methods for the agents.
*/
class GameManager
{
		public : 
		//std::vector<Agent*> agents;
		std::vector<Agent*> agents;
		//!Returns true if another agent is within a certain distance.
		bool DetectAgent(Agent*);
		GameManager(std::vector<Agent*> passed_agents);
		~GameManager();		
};