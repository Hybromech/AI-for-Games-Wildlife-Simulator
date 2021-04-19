#pragma once

#include "Idle.h"

	Idle::Idle(const Agent* agent) {}
	Idle::~Idle() {};
	bool Idle::Update(Agent*, float deltatime)
	{
		std::cout << "State is Idle" << std::endl;
		return true;
	}
