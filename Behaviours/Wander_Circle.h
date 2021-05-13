#pragma once
#include  <glm/glm.hpp>
//!A wander circle structure 
struct Circle
{
	//!The origin of the circle.
	glm::vec2 origin;
	//!The radius of the circle.
	float radius = 30;// = hypotenuse.
	//!The target point the agent should move to.
	glm::vec2 target_point;
	//!The x position for the point of interest.
	float outer_x;
	//!The y position for the point of interest
	float outer_y;
	//!Variable to store the given angle.
	float angle = 0;//random
};

			
			



	