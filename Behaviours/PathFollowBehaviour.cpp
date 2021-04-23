#include "PathFollowBehaviour.h"
#include "iostream"
#include "Agent.h"
Behaviours::PathFollowBehaviour::PathFollowBehaviour(float speed) : m_speed{ speed } {}

void Behaviours::PathFollowBehaviour::SetPath(const Path& path) { //create new path
	current_path.clear();
	current_path.insert(
		current_path.begin(),
		path.begin(), path.end()
	);

	next_node = 1; //next node in sequence.
}

bool Behaviours::PathFollowBehaviour::Update(Agent* agent, float deltatime) {
	//If at end stop.
	std::cout << "current_path.size" << current_path.size();
	if (next_node >= current_path.size()) {
		glm::vec2 vec{ 0 };
		agent->SetVelocity(vec);
		return false;
	}
		
	//work out vector towards next goal node
	//move toward next goal node
	//if we reach it
	//advance goal to next node in path
	//if we reach the end
	//reverse stop or whatever.
	auto full_vector = current_path[next_node]->position - agent->GetPosition();
	float length = glm::length(full_vector);
	auto vector_to_next_node = glm::normalize(full_vector);
	
	float speed = m_speed;

	//Check if we are about to reach the next node.
	if (length < m_speed * deltatime) {
		next_node++;
		speed = length / deltatime;
	}

	agent->SetVelocity(vector_to_next_node * m_speed);
	return false;
}