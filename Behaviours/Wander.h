#include "Behaviour.h"
#include "SteeringBehaviour.h"
#include <iostream>
#include "Wander_Circle.h"
#include "Timer.cpp"


class Wander : public Behaviour
{
private:
	const Agent* agent;//does not need to be a shared pointer.
	Behaviours::SteeringBehaviour* steering;
	Circle circle;

	Timer timer;
public:
	Wander(const Agent* agent, Behaviours::SteeringBehaviour* sb, Circle c, Timer t);
	~Wander();
	bool Update(Agent*, float deltatime);
	
	Circle updateCircle(Circle c, float min, float max, float radius, bool gen_rand);
	void DrawDebugCircle();
};






