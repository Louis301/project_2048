#include "Key_Handler.hpp"
#include "Event.hpp"

EInteractionLayer Key_Handler::Interaction_Layer = EIL_Main_Screen;


// ----------------------------------------------------------------------------------------------------
void Key_Handler::On_C()
{
	switch(Interaction_Layer)
	{
		case EIL_Main_Screen: 
			As_Event::Continue_Game();
			break;
	}
}

// ----------------------------------------------------------------------------------------------------
void Key_Handler::On_Esc()
{
	switch(Interaction_Layer)
	{
		case EIL_Main_Screen: 
			As_Event::Stop_Program();
			break;
		
		case EIL_Record_Table_Screen: 
			// ...
			break;
	}
}

// ----------------------------------------------------------------------------------------------------
void Key_Handler::On_R()
{		
	switch(Interaction_Layer)
	{
		case EIL_Main_Screen: 
			As_Event::Restart_Game();
			break;
	}
}

// ----------------------------------------------------------------------------------------------------
void Key_Handler::On_Space()
{
	// таблица рекордов
	
	switch(Interaction_Layer)
	{
		case EIL_Main_Screen: 
			As_Event::Show_Record_Table();
			break;
	}
}
		
// ----------------------------------------------------------------------------------------------------
void Key_Handler::On_Up()
{
	switch(Interaction_Layer)
	{
		case EIL_Main_Screen: 
			As_Event::Game_Field_Interaction(EOD_To_Up);
			break;
	}
}

// ----------------------------------------------------------------------------------------------------
void Key_Handler::On_Down()
{
	switch(Interaction_Layer)
	{
		case EIL_Main_Screen: 
			As_Event::Game_Field_Interaction(EOD_To_Down);
			break;
	}
}

// ----------------------------------------------------------------------------------------------------
void Key_Handler::On_Left()
{
	switch(Interaction_Layer)
	{
		case EIL_Main_Screen: 
			As_Event::Game_Field_Interaction(EOD_To_Left);
			break;
	}
}

// ----------------------------------------------------------------------------------------------------
void Key_Handler::On_Right()
{
	switch(Interaction_Layer)
	{
		case EIL_Main_Screen: 
			As_Event::Game_Field_Interaction(EOD_To_Right);
			break;
	}
}
