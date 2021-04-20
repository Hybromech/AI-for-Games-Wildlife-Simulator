#pragma once
#include "Agent.h"
	
	class Behaviour
	{
		public:
		virtual bool Update(Agent*, float deltatime) = 0; 
	}; 

