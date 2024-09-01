#include "System_Message.hpp"

// ----------------------------------------------------------------------------------------------------
std::string As_System_Message::System_Msg = "";
// ----------------------------------------------------------------------------------------------------
void As_System_Message::Reset() { 
	As_System_Message::Set(""); 
}
// ----------------------------------------------------------------------------------------------------
void As_System_Message::Set(std::string message) 
{ 
	As_System_Message::System_Msg = message; 
}
// ----------------------------------------------------------------------------------------------------
std::string As_System_Message::Get() 
{ 
	return As_System_Message::System_Msg; 
}
