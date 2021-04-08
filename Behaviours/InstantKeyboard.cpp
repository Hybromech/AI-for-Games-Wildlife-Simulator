#include "InstantKeyboard.h"
#include "Agent.h"
#include <glm/glm.hpp>
#include <raylib.h>

InstantKeyboard::InstantKeyboard(float s)
: Behaviour()//Initialiser lists.
, m_speed{ s } 
{}

InstantKeyboard::~InstantKeyboard() {};

bool InstantKeyboard::Update(Agent* agent, float deltatime) {//Behaviours are not specific to one agent.
	glm::vec2 offset = { 0,0 };
	if (IsKeyDown(KEY_UP)) 
		offset.y = -m_speed;
	if (IsKeyDown(KEY_DOWN))
		offset.y = m_speed;
	if (IsKeyDown(KEY_LEFT))
		offset.x = -m_speed;
	if (IsKeyDown(KEY_RIGHT))
		offset.x = m_speed;
	agent->SetVelocity(offset * deltatime);//instant movement.
	return 1;
}