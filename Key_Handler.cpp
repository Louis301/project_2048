#include "Key_Handler.hpp"
#include "Event.hpp"

// ----------------------------------------------------------------------------------------------------
void Key_Handler::On_C()
{
	As_Event::Continue_Game();
}
// ----------------------------------------------------------------------------------------------------
void Key_Handler::On_Esc()
{
	if (As_Program::Get_Interaction_Layer() == EIL_Viewing_Results)
	  As_Event::Continue_Game();
	else
	  As_Event::Stop_Program(); 
}
// ----------------------------------------------------------------------------------------------------
void Key_Handler::On_R()
{		
	As_Event::Restart_Game();
}
// ----------------------------------------------------------------------------------------------------
void Key_Handler::On_Space()
{
	As_Event::Record_Table_Interaction();
}		
// ----------------------------------------------------------------------------------------------------
void Key_Handler::On_Up()
{
	As_Event::Game_Field_Interaction(EOD_To_Up);
}
// ----------------------------------------------------------------------------------------------------
void Key_Handler::On_Down()
{
	As_Event::Game_Field_Interaction(EOD_To_Down);
}
// ----------------------------------------------------------------------------------------------------
void Key_Handler::On_Left()
{
	As_Event::Game_Field_Interaction(EOD_To_Left);
}
// ----------------------------------------------------------------------------------------------------
void Key_Handler::On_Right()
{
	As_Event::Game_Field_Interaction(EOD_To_Right);
}
