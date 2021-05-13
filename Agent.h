#pragma once

#include <vector>
#include <memory>
#include <glm/glm.hpp>
#include <raylib.h>
#include <ChasePlayerState.h>
#include "StateMachine.h"
#include<WanderState.h>

class GameManager;

extern int screenx; //Dirty don't use
extern int screeny; //Dirty don't use

class Behaviour; //Use forward declare instead of include as much as possible.
class StateMachine;

///Base entity game unit.
/** Can modify position of self.
Can pass information to the statemachine.
Can detect another agent.
*/

class Agent
{
	public:
	Agent(Texture t, StateMachine* sm, GameManager* gm);
	~Agent();

	/*! \brief base update method.
	* Updates the agent.
	*/

	virtual void Update(float deltaTime);
	
	/*! Draw the agent on screen.*/

	virtual void Draw();

	/*! Adds a behaviour */

	void AddBehaviour(Behaviour*);
	
	/*! The unique agent ID number */
	
	int ID;

	//Movement functions
	
	/*! Sets the position of the agent. */
	
	void SetPosition(glm::vec2 position);
	
	/*! Gets the position of the agent. */
	
	const glm::vec2& GetPosition() const;

	/*! Sets the velocity for the agent. */

	void SetVelocity(glm::vec2 velocity);

	/*! Gets the velocity of the agent. */

	const glm::vec2& GetVelocity() const;
	
	/*! Adds forces to the agent. */
	
	void AddForce(glm::vec2 force); //Mostly used by Behaviours
	
	/*! Detects other agents based on distance, returns false if the check fails. */
	
	bool DetectAgent(Agent*);
	WanderState* wanderState;
	ChasePlayerState* chaseState;
	GameManager* gameManager;
	StateMachine* sm;
	//! The current speed of the agent
	float speed = 0;
	//! The speed at which the agent will travel while wandering
	float wanderSpeed = 5;
	//float fleeSpeed = 70;
	//float chaseSpeed = 65;
	//! The maximum speed the agent can move
	float max_speed = 10000;
	//! The maximum force the agent can apply to itself
	float max_force = 40.5;

	//Animation
	//! The initial X frame position the animation starts on 
	int initial_frame_x = 4;
	//! The initial Y frame position the animation starts on 
	int initial_frame_y = 0;
	//! The speed of the animation
	float frames_ps = 15;
	//! How many frames to cycle
	int steps = 8;
	//! Array of Behaviours
	std::vector<std::shared_ptr<Behaviour>> m_behaviours; //Must store base class as a pointer to maintain data.
private: 
	
	//! The agents current position
	glm::vec2 m_position = { 0,0 };
	//! The agents current velocity
	glm::vec2 m_velocity = { 0,0 };
	//! The agents current force
	glm::vec2 m_force = { 0,0 };
	//! The agents colour
	Color colour{0,0,0};
	//! The agents texture
	Texture texture;
};