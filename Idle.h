#pragma once

#include "Behaviour.h"
#include "iostream"

//!An idle Behaviour 
class Idle : public Behaviour
{
private:
	const Agent* agent;//does not need to be a shared pointer.
public:
	Idle(const Agent* agent);
	~Idle();
	bool Update(Agent*, float deltatime);	
};