#pragma once

#include "SteeringBehaviour.h"
#include <iostream>

struct Circle
{
	glm::vec2 origin;
	float radius = 50;// = hypotenuse
	glm::vec2 target_point;
	float outer_x;
	float outer_y;
	float angle;//random
};
			
			Circle updateCircle(Circle c, float min, float max, float radius, bool gen_rand)
			{
				if(gen_rand)
				c.angle = GetRandomValue(min, max);//Get a random angle
			//calculate x and y position of point based on that angle
				c.outer_x = radius * cos(c.angle);
				c.outer_y = radius * sin(c.angle);

				c.target_point.x = c.origin.x + c.outer_x;
				c.target_point.y = c.origin.y + c.outer_y;
				return c;
			}//information to calcuate a random point on the circle
		
		
		//Circle makeCircle(glm::vec2 origin, float radius, float min, float max)
		//{
		//	//create a circle and call get random point to get a new target point.
		//	Circle circle{ origin , radius, };
		//	circle.target_point = getRandomPoint(min, max, radius);

		//	return circle;
		//}
		void DrawCircle(Circle c)
		{
			//std::cout << "Drawing circle" << std::endl;
			DrawCircleLines(c.origin.x, c.origin.y,c.radius, { 255,0,0,255 });//draw the circle.
			DrawCircle(c.target_point.x, c.target_point.y, 8, { 0,0,255,255 });
		}



	