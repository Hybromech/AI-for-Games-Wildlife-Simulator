#pragma once
class Agent;

class Behaviour
{
public:
	virtual void Update(Agent*, float deltatime) = 0;
};