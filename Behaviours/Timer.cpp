#include <iostream>
struct Timer
{
	//Behaviours::PathFollowBehaviour::PathFollowBehaviour(float speed) : m_speed{ speed } {}
	
		double currentTime;
		int endFrame;
		int startFrame;
		Timer(double ct) : currentTime{ ct }{
			startFrame = currentTime;
			endFrame = currentTime + 2;
		};
		~Timer(){};
	
	int reset_Timer(double currentTime)
	{
		int startFrame;
		startFrame = currentTime;  // Returns elapsed time in seconds since InitWindow()
		return startFrame;
	}
	int set_endTime(int startFrame)
	{
		return endFrame = startFrame + 2;
	}
	bool update_timer(double currentTime, int endFrame)
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
