#pragma once
#include <glm/glm.hpp>

class SteeringForce
{
public:
	virtual glm::vec2 GetForce(class Agent*) = 0;
};

