#pragma once

#include<glm/glm.hpp>
#include<Graph.h>
#include"Behaviour.h"

namespace Behaviours {
	///Contains function that manipulate the path.
	/**
	*/
	class PathFollowBehaviour : public Behaviour //Derives from base behaviour class publicly
	{
	private:
		//!The speed that the agent will follow the path.
		float m_speed = 1.0f;
		//!The current path
		std::vector<Node*> current_path;
		//!Variable to hold the next node in the path
		int next_node;
		public:
			PathFollowBehaviour(float speed);//Constructor
		//!Sets a new path supplied by 'path'.
		void SetPath(const Path& path); //create new path
		//!Stops the agent upon reaching its final node.
		bool Update(Agent*, float deltatime);
				
	};
}
