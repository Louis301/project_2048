#include "Program.hpp"
#include "Key_Handler.hpp"
#include "User_Interface.hpp"
#include "InternalData.hpp"
#include <conio.h>

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
};
// ----------------------------------------------------------------------------------------------------
void As_Program::Set_Internal_Data()
{	
	As_Game_Field::Reset();
	As_System_Message::Reset();
	
	As_Total_Score::Reset();
	As_Record_Table::Reset();
}
// ----------------------------------------------------------------------------------------------------
void As_Program::Draw_UI()  // для первого экрана
{
	As_UI_Game_field::Set_Draw_Position(0, 0);
	As_UI_Game_field::Show_Static(true);
	As_UI_Game_field::Show_Dynamic(true);
	
	As_UI_System_Msg::Set_Draw_Position(0, 2 * As_Game_Field::Game_Field.size() + 1);
	As_UI_System_Msg::Show_Dynamic(false);
	
	As_UI_Total_Score::Set_Draw_Position(As_Game_Field::Game_Field.size() * 5 + 4, 1);
	As_UI_Total_Score::Show_Static(true);
	As_UI_Total_Score::Show_Dynamic(true);
	
	As_UI_Control_Info::Set_Draw_Position(As_Game_Field::Game_Field.size() * 5 + 4, 3);    // Здесь нужен cell_width
	As_UI_Control_Info::Show_Static(true);
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
