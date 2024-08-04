#include "Key_Handler.hpp"
#include "Event.hpp"

EInteractionLayer Key_Handler::Interaction_Layer = EIL_Main_Screen;


// ----------------------------------------------------------------------------------------------------
void Key_Handler::On_C()
{
//	if (Interaction_Layer == EIL_Main_Screen)
//	{
//		std::cout << "On_C()  " << "ok";
//	}
//	else
//	{
//		std::cout << "else C";
//	}

//EIL_Main_Screen,
//	EIL_Record_Table_Screen
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
}

// ----------------------------------------------------------------------------------------------------
void Key_Handler::On_Space()
{
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
