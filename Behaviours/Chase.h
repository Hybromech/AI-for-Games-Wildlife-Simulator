#pragma once
#include <glm/glm.hpp>
#include "Behaviour.h"
///A behaviour that makes the agent chase another agent.
/**
*/
class Chase : public Behaviour
{
private:
	//!The target agent to chase
	const Agent* m_target;//does not need to be a shared pointer.
	//!The speed when chasing.
	float m_speed;
public: 
	Chase(const Agent* target, float speed);
	~Chase();
	 bool Update(Agent*, float deltatime);
};