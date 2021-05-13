#pragma once
#include <glm/glm.hpp>
///Class that handles steering forces.
/** 
*/

class SteeringForce
{
public:
	//!Sets the internal point target variable to the provided point. 
	virtual void Set_point(glm::vec2) = 0;
	//!Returns a force in the direction of the agent.
	virtual glm::vec2 GetForce(class Agent*) = 0;//pure virtual function
	//!Returns a force in the direction of the agent.
	virtual glm::vec2 GetForce_point(Agent* agent) = 0;
};

