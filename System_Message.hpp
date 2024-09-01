#pragma once 
#include <string>

// ----------------------------------------------------------------------------------------------------
class As_System_Message
{
	private:
		static std::string System_Msg;
		
	public:
		static void Reset();  
		static void Set(std::string message);
		static std::string Get();
};
