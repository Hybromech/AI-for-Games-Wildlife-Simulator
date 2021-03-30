#include "KeyboardBehaviour.h"
#include "Agent.h"
#include <glm/glm.hpp>
#include <raylib.h>

KeyboardBehaviour::KeyboardBehaviour() : Behaviour() {};
KeyboardBehaviour:: ~KeyboardBehaviour() {};

void KeyboardBehaviour::Update(Agent* agent, float deltatime) {
	glm::vec2 force = { 0,0 };
	if(IsKeyDown(KEY_UP))
		force.y = -m_speed;
	if (IsKeyDown(KEY_DOWN))
		force.y = m_speed; 
	if (IsKeyDown(KEY_LEFT))
		force.x = -m_speed;
	if (IsKeyDown(KEY_RIGHT))
		force.x = m_speed;	
	agent->AddForce(force * deltatime);
}