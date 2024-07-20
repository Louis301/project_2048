#include "Key_Handler.hpp"
#include "Event.hpp"

//As_Event::Exit_Program();


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
}

// ----------------------------------------------------------------------------------------------------
void Key_Handler::On_Down()
{
}

// ----------------------------------------------------------------------------------------------------
void Key_Handler::On_Left()
{
}

// ----------------------------------------------------------------------------------------------------
void Key_Handler::On_Right()
{
}
