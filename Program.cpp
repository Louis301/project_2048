#include "Program.hpp"
#include "Key_Handler.hpp"
#include "User_Interface.hpp"
#include "Game_Field.hpp"
#include "Total_Score.hpp"
#include "System_Message.hpp"
#include <conio.h>

bool As_Program::Exit_Program = false;

EInteractionLayer As_Program::Interaction_Layer = EIL_Matrix_Management;

enum EKeys   // дл€ строчных букв
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
}
// ----------------------------------------------------------------------------------------------------
void As_Program::Draw_UI()  // дл€ первого отображени€ экрана
{
	As_UI_Game_field::Set_Draw_Position(0, 0);
	As_UI_Game_field::Show_Static(true);
	As_UI_Game_field::Show_Dynamic(true);
	
	As_UI_Total_Score::Set_Draw_Position(As_Game_Field::Game_Field.size() * 5 + 4, 1);
	As_UI_Total_Score::Show_Static(true);
	As_UI_Total_Score::Show_Dynamic(true);
	
	As_UI_Control_Info::Set_Draw_Position(As_Game_Field::Game_Field.size() * 5 + 4, 3);    
	As_UI_Control_Info::Show_Static(true);
}
// ----------------------------------------------------------------------------------------------------
void As_Program::Start_Controller()
{	
	while(!Exit_Program)
	{
		switch(getch())
		{
			case EK_ESC: 	
				Key_Handler::On_Esc();		
				break;
				
			case EK_UP: 
				if (As_Program::Get_Interaction_Layer() == EIL_Matrix_Management)
					Key_Handler::On_Up();		
				break;
			
			case EK_DOWN:
				if (As_Program::Get_Interaction_Layer() == EIL_Matrix_Management)
					Key_Handler::On_Down();		
				break;
			
			case EK_LEFT:
			 	if (As_Program::Get_Interaction_Layer() == EIL_Matrix_Management)
					Key_Handler::On_Left();		
				break;
			
			case EK_RIGHT:
				if (As_Program::Get_Interaction_Layer() == EIL_Matrix_Management)
					Key_Handler::On_Right();	
				break;
			
			case EK_C: 
			 	if (As_Program::Get_Interaction_Layer() == EIL_Winning)
					Key_Handler::On_C();		
				break;
			
			case EK_R:		
			 	if (As_Program::Get_Interaction_Layer() == EIL_Losing or 
				 	As_Program::Get_Interaction_Layer() == EIL_Matrix_Management)
					Key_Handler::On_R();		
				break;
			
			case EK_SPACE:	
			 	if (As_Program::Get_Interaction_Layer() == EIL_Matrix_Management)
					Key_Handler::On_Space();	
				break;			
			
			default:										
				break;	
		}	
	}
}
// ----------------------------------------------------------------------------------------------------
EInteractionLayer As_Program::Get_Interaction_Layer()
{
	return As_Program::Interaction_Layer;
}
// ----------------------------------------------------------------------------------------------------
void As_Program::Set_Interaction_Layer(EInteractionLayer inter_layer)
{
	As_Program::Interaction_Layer = inter_layer;
}
