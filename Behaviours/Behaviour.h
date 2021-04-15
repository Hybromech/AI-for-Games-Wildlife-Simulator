#pragma once
#include "Agent.h"
class Agent;

	class Behaviour
	{
		public:
		virtual bool Update(Agent*, float deltatime) = 0;
		virtual bool Update(glm::vec2, float deltatime) = 0;
	};

