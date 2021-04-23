#pragma once

#include <vector>
#include <memory>
#include <glm/glm.hpp>
#include <raylib.h>
#include <ChasePlayerState.h>
#include<WanderState.h>
class GameManager;

extern int screenx; //Dirty don't use
extern int screeny; //Dirty don't use

class Behaviour; //Use forward declare instead of include as much as possible.
class StateMachine;

class Agent
{
	public:
	Agent(Texture t, StateMachine* sm, GameManager* gm);
	~Agent();

	virtual void Update(float deltaTime, StateMachine* sm);
	virtual void Draw();

	void AddBehaviour(Behaviour*);
	int ID;

	//Movement functions
	void SetPosition(glm::vec2 position);
	const glm::vec2& GetPosition() const;
	void SetVelocity(glm::vec2 velocity);
	const glm::vec2& GetVelocity() const;
	void AddForce(glm::vec2 force); //Mostly used by Behaviours

	WanderState* wanderState;
	ChasePlayerState* chaseState;
	GameManager* gameManager;
	
	float max_speed = 10000000;
	float max_force = 500;

	//Animation
	int initial_frame_x = 4;
	int initial_frame_y = 0;
	float frames_ps = 15;
	int steps = 8;

	std::vector<std::shared_ptr<Behaviour>> m_behaviours; //Must store base class as a pointer to maintain data.
private: 
	
	glm::vec2 m_position = { 0,0 };
	glm::vec2 m_velocity = { 0,0 }; 
	glm::vec2 m_force = { 0,0 };

	Color colour{0,0,0};
	Texture texture;
	StateMachine* sm;
};