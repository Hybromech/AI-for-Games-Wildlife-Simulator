#pragma once
#include "SteeringForce.h"
#include "Agent.h"

class SeekForce : public SteeringForce
{
private:
	Agent* target;
public:
	SeekForce(Agent* t) : SteeringForce{}, target{ t }
	{}
	virtual glm::vec2 GetForce(Agent* agent) override{
		auto desired_velocity = glm::normalize(target->GetPosition() - agent->GetPosition()) * agent->max_speed;
		auto steering_force = desired_velocity - agent->GetVelocity();
		return steering_force;
	}
};

class FleeForce : public SeekForce
{
public:
	FleeForce(Agent* t) : SeekForce(t) {}
		virtual glm::vec2 GetForce(Agent* agent) override {
			return -SeekForce::GetForce(agent);
		
	}
};