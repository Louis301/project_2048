#include "Program.hpp"
#include "Key_Handler.hpp"
#include "User_Interface.hpp"
#include "InternalData.hpp"

#include "conio.h"

//As_Game_Field::Reset();
//	As_System_Message::Reset();
//	As_Total_Score::Reset();
//	As_Record_Title::Reset();

bool As_Program::Exit_Program = false;


enum EKeys   // для строчных букв
{
	EK_ESC = 27,
	EK_UP = 72,
	EK_DOWN = 80,
	EK_LEFT = 75,
	EK_RIGHT = 77,
	EK_C = 99,
	EK_R = 114,
	EK_SPACE = 32
//	EK_W = 119,
//	EK_S = 115,
//	EK_A = 97,
//	EK_D = 100,
//	EK_ESC = 27,
//	EK_UP = 72,
//	EK_DOWN = 80,
//	EK_LEFT = 75,
//	EK_RIGHT = 77,
//	EK_ENTER = 13,
//	EK_Y = 121,
//	EK_N = 110
};


// ----------------------------------------------------------------------------------------------------
void As_Program::Set_Internal_Data()
{	
	As_Game_Field::Reset();
	As_System_Message::Reset();
	As_Total_Score::Reset();
	As_Record_Title::Reset();
}

// ----------------------------------------------------------------------------------------------------
void As_Program::Draw_UI()  // для первого экрана
{
	As_UI_Game_field::Show();
	As_UI_System_Msg::Show();
	As_UI_Control_Info::Show();
	As_UI_Total_Score::Show();	
}

// ----------------------------------------------------------------------------------------------------
void As_Program::Start_Controller()
{
	while(!Exit_Program)
	{
		switch(getch())
		{
			case EK_ESC: 	Key_Handler::On_Esc();		break;
			case EK_UP:		Key_Handler::On_Up();		break;
			case EK_DOWN:	Key_Handler::On_Down();		break;
			case EK_LEFT:	Key_Handler::On_Left();		break;
			case EK_RIGHT:	Key_Handler::On_Right();	break;
			case EK_C:		Key_Handler::On_C();		break;
			case EK_R:		Key_Handler::On_R();		break;
			case EK_SPACE:	Key_Handler::On_Space();	break;
			
			default:									break;	
		}	
	}
}

