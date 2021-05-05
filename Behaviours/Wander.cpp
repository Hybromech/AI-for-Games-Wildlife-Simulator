#include "Wander.h"


Wander::Wander(Behaviours::SteeringBehaviour* sb, Circle c, Timer t)
	: Behaviour(), steering{ sb }, circle{ c }, timer{ t }
{}

Wander::~Wander() {}

bool Wander::Update(Agent* agent, float deltaTime) {
	agent->speed = agent->wanderSpeed;
	circle = updateCircle(circle,0,360,30,false);
	
	circle.origin = agent->GetPosition();
	if (timer.update_timer(GetTime(), timer.endFrame) == true)//if the timer is fired //double currentTime, int startFrame, int endFrame
	{
		timer.startFrame = timer.reset_Timer(GetTime());
		std::cout << "start time" << timer.startFrame << std::endl;
		timer.endFrame = timer.set_endTime(timer.startFrame);
		circle = updateCircle(circle,-90, 90, 30, true);//update circle with randomised target point
	}

	steering->force->Set_point(circle.target_point);
	steering->Update(agent, deltaTime);
	DrawDebugCircle();
	return 1;
}

Circle Wander::updateCircle(Circle c, float min, float max, float radius, bool gen_rand)
{
	if (gen_rand)
	{
		auto getRandomV = GetRandomValue(min, max);
		std::cout << "__getRandomV X " << getRandomV;
		c.angle = c.angle + getRandomV;
	}
		
		std::cout << c.angle << std::endl;
		std::cout << "__Origin X " << c.origin.x;
		std::cout << "__Origin Y " << c.origin.y;
		std::cout << "__Angle " << c.angle;
		
		if (c.angle > 360)
			c.angle -= 360;
		
		if (c.angle < 0)
			c.angle += 360;

		//c.angle = GetRandomValue(min, max);//Get a random angle from 0 to 360
		
		//calculate x and y position of point based on that angle
	c.outer_x = radius * cos(c.angle * 3.14159265359 /180);//PI / 180
	c.outer_y = radius * sin(c.angle * 3.14159265359 / 180);

	c.target_point.x = c.origin.x + c.outer_x;
	c.target_point.y = c.origin.y + c.outer_y;
	return c;
}//information to calcuate a random point on the circle

void Wander::DrawDebugCircle()
{
	//std::cout << "Drawing circle" << std::endl;
	DrawCircleLines(circle.origin.x, circle.origin.y, circle.radius, { 255,0,0,255 });//draw the circle.
	DrawCircle(circle.target_point.x, circle.target_point.y, 8, { 0,0,255,255 });
}