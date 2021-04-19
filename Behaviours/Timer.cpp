#pragma once
#include <iostream>
struct Timer
{
	//Behaviours::PathFollowBehaviour::PathFollowBehaviour(float speed) : m_speed{ speed } {}
	
		double currentTime;
		float endFrame;
		float startFrame;
		Timer(double ct) : currentTime{ ct }{
			startFrame = currentTime;
			endFrame = currentTime + 1.6f;
		};
		~Timer(){};
	
	float reset_Timer(double currentTime)
	{
		float startFrame;
		startFrame = currentTime;  // Returns elapsed time in seconds since InitWindow()
		return startFrame;
	}
	float set_endTime(float startFrame)
	{
		return endFrame = startFrame + 1.6f;
	}
	bool update_timer(double currentTime, float endFrame)
	{
		std::cout << "current time" << currentTime << std::endl;
		std::cout << "end time" << endFrame << std::endl;
		if (currentTime >= endFrame)
		{
			std::cout << "!!!!!!!!!!!!!!!!!!!Timer has Fired!!!!!!!!!!!!!!!!!!!" << std::endl;
			return true; //timer has fired
		}
		else return false;//timer has not fired
	}
};
