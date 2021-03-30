#pragma once
#include "Behaviour.h"
#include "SteeringForce.h"
#include "Agent.h"
class SteeringBehaviour : public Behaviour
{
private:
	SteeringForce* force;
public:
	SteeringBehaviour(SteeringForce* f) : Behaviour(), force{ f }{};//Constructor 

	// Inherited via Behaviour
	virtual void Update(Agent* agent, float deltatime) override
	{
		agent->AddForce(force->GetForce(agent));
	}

};