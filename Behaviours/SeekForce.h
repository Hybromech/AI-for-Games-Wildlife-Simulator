#pragma once
#include "SteeringForce.h"
#include "Agent.h"

class SeekForce : public SteeringForce
{
	private:
	Agent* target;
	public:
	glm::vec2 point_target;
	SeekForce(Agent* t) : SteeringForce{}, target{ t }
	{}
	SeekForce(glm::vec2 t) : SteeringForce{}, point_target{ t }
	{}

	virtual void Set_point(glm::vec2 point_set)override {
		point_target = point_set;
	}
	virtual glm::vec2 GetForce(Agent* agent) override {
		auto desired_velocity = glm::normalize(target->GetPosition() - agent->GetPosition()) * agent->max_speed;
		auto steering_force = desired_velocity - agent->GetVelocity();
		return steering_force;
	}
		virtual glm::vec2 GetForce_point(Agent * agent) override {
			auto desired_velocity = glm::normalize(point_target - agent->GetPosition()) * agent->max_speed;
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