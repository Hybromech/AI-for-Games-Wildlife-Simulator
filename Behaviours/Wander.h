#include "Behaviour.h"
#include "SteeringBehaviour.h"
#include <iostream>
#include "Wander_Circle.h"
#include "Timer.cpp"

//!A behaviour that makes the agent wander in a random direction.
class Wander : public Behaviour
{
private:
	//const Agent* agent;//does not need to be a shared pointer.
	//!A steering object used to apply a force.
	Behaviours::SteeringBehaviour* steering;
	//!A circle object used to calcualte a wandering force
	Circle circle;
	//!A timer object that counts down required time, used to reset the wander target.
	Timer timer;
public:
	Wander(Behaviours::SteeringBehaviour* sb, Circle c, Timer t);
	~Wander();
	//!Sets the agents speed to wanderspeed, updates the circle, If the Timer expires then it randomises the target point on the circle.
	bool Update(Agent*, float deltatime);
	
	//!Generates a random vector.
	//!Min and max are the range that the random angle will be generated.
	//!Radius is size of the wander circle.
	//!Gen_rand, should the method generate a random vector.
	Circle updateCircle(Circle c, float min, float max, float radius, bool gen_rand);
	void DrawDebugCircle();
};






