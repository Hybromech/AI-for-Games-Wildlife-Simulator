#include "Agent.h"
#include "Behaviour.h"
#include <raylib.h>
#include <string>


int screenx = 200; //Dirty don't use
int screeny = 200; //Dirty don't use



Agent::Agent(Texture t, StateMachine* s) : texture{ t }, sm(s)  {
	//wanderState = new WanderState();
	//chaseState = new ChasePlayerState();
};//Initialse colour with the item passed into the constructor.
Agent::~Agent() {};


void Agent::Update(float deltaTime, StateMachine* sm){
	
	m_force = {0,0};
	sm->update(this,sm,deltaTime);
	//for (auto b : m_behaviours) { //Update all behaviours 
	//	b->Update(this,deltaTime);
	//}
	m_velocity += m_force * deltaTime;
#ifndef NDEBUG
	////Draw velocity vector.
	//DrawLine(m_position.x, m_position.y,
	//	m_position.x + m_position.x, m_position.y + m_position.y, GREEN);

	////Draw Force
	//DrawLine(m_position.x, m_position.y,
	//	m_force.x + m_force.x, m_force.y + m_force.y, BLUE);
#endif

	//We need to clamp velocity to equal or below maxium.
	float magnitude = glm::length(m_velocity);
	//if velocity is too high clamp it down.
	//normalize the vector and multiply it by max_speed.
	if (magnitude > max_speed) {
		m_velocity = glm::normalize(m_velocity) * max_speed;
	}
	m_position += m_velocity * deltaTime;
	//Wrap around
	if (m_position.x < 0)m_position.x += screenx;
	if (m_position.y < 0)m_position.y += screeny;

	if (m_position.x > screenx)m_position.x -= screenx;
	if (m_position.y > screeny)m_position.y -= screeny;
};
void Agent::Draw() {
	//const char* file_name = "robot_sprite1.png";
	//Texture2D texture = LoadTexture(file_name);
	//DrawTexture(texture, m_position.x, m_position.y,RAYWHITE);//Draw the texture
	
	//DrawRectangle(m_position.x, m_position.y, 10, 10, colour);

	constexpr int sz = 32;
	
	int currentframex = initial_frame_x + int( GetTime() * frames_ps ) % steps;
	int currentframey = initial_frame_y;
	
	Rectangle source{ sz * currentframex,sz * currentframey ,sz,sz };

	const int width = sz;
	const int height = sz;
	
	
	Rectangle destination{ m_position.x, m_position.y, width,height };

	float angle = atan2f(m_velocity.y, m_velocity.x) * 180/3.141459f + 90;
	
	DrawTexturePro(
		texture,
		source,
		destination,
		{ width / 2,height / 2 },angle,
		{255,255,255,255});//Draw the texture 
	//black bug Rectangle source{ 0,32,32,64 };
};

void Agent::AddBehaviour(Behaviour* behaviour) {
	m_behaviours.emplace_back(behaviour);//construct a shared pointer //(std::shared_ptr<Behaviour>(behaviour));
}

//Movement functions
void Agent::SetPosition(glm::vec2 position){
	m_position = position;
}
const glm::vec2& Agent::GetPosition() const {
	return m_position;
}
void Agent::SetVelocity(glm::vec2 velocity) {
	m_velocity = velocity;
}

const glm::vec2& Agent::GetVelocity() const {
	return m_velocity;
}

void Agent::AddForce(glm::vec2 force){
	m_force += force;
}