#pragma once
class Agent;
	
	class Behaviour
	{
		public:
		virtual bool Update(Agent*, float deltatime) = 0; 
	}; 

