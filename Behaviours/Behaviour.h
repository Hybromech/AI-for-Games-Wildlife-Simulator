#pragma once
class Agent;
	
///Base behaviour class.
/**All behaviours inherit from this class*/
	class Behaviour
	{
		public:
			//!Base Update method.
			virtual bool Update(Agent*, float deltatime) = 0;
	}; 
