#include "Chase.h"
#include "Agent.h"

Chase::Chase(const Agent* target, float speed)
	: Behaviour()
	, m_target{target}
	, m_speed{speed}
{}

Chase::~Chase() {}

bool Chase::Update(Agent* agent, float deltaTime){
//calculate the direction to the target.
	auto V = glm::normalize(m_target->GetPosition() - agent->GetPosition());
    auto Force = V * m_speed * deltaTime;
	agent->AddForce(Force);
	
	return 1;
}