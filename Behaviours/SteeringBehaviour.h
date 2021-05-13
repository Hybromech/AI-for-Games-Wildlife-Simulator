#pragma once
#include "SteeringForce.h"
#include "Agent.h"

namespace Behaviours
{
	///Base class for steering behaviours.
	/**
	*/
	class SteeringBehaviour : public Behaviour
	{
	public:
		SteeringForce* force;
	public:
		SteeringBehaviour(SteeringForce* f) : Behaviour(), force{ f }{};//Constructor 

		//Inherited via Behaviour
		//!Adds a force to the given agent.
		virtual bool Update(Agent* agent, float deltatime) override
		{
			agent->AddForce(force->GetForce_point(agent));
			return 1;
		}
	};
}
