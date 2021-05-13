#pragma once

///Provides methods that return a steering force.
/**
*/

class SeekForce : public SteeringForce
{
	private:
	//!The target agent.
	Agent* target;
	public:
	//! An arbitry point that can be used to apply a force.
	glm::vec2 point_target;
	SeekForce(Agent* t) : SteeringForce{}, target{ t }
	{}
	SeekForce(glm::vec2 t) : SteeringForce{}, point_target{ t }
	{}
	//!Sets the position of a point.
	virtual void Set_point(glm::vec2 point_set)override {
		point_target = point_set;
	}
	//!Returns a steering force based on given agents position.	
	virtual glm::vec2 GetForce(Agent* agent) override {
		auto desired_velocity = glm::normalize(target->GetPosition() - agent->GetPosition()) * agent->speed;
		auto steering_force = desired_velocity - agent->GetVelocity();
		return steering_force;
	}
	//!Returns a steering force based on given point.
	virtual glm::vec2 GetForce_point(Agent * agent) override {
			auto desired_velocity = glm::normalize(point_target - agent->GetPosition()) * agent->speed;
			auto steering_force = desired_velocity - agent->GetVelocity();
			return steering_force;
	}
};
//!Has a function to return the inverse force
class FleeForce : public SeekForce
{
public:
	FleeForce(Agent* t) : SeekForce(t) {}
		virtual glm::vec2 GetForce(Agent* agent) override {
			return -SeekForce::GetForce(agent);
		
	}
};