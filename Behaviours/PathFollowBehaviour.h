#pragma once

#include "Behaviour.h"
#include "Graph.h"
#include <vector>


namespace Behaviours {
	class PathFollowBehaviour : public Behaviour //Derives from base behaviour class publicly
	{
	private:
		float m_speed = 1.0f;
		std::vector<Node*> current_path;
		int next_node;
		public:
			PathFollowBehaviour(float speed);//Constructor
		
		void SetPath(const Path& path); //create new path
		
		bool Update(Agent*, float deltatime);
				
	};
}