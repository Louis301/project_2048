#include "User_Interface.hpp"
#include "InternalData.hpp"
#include <windows.h>
#include <conio.h>

// ----------------------------------------------------------------------------------------------------
int As_UI_Game_field::X_Offset = 0;
int As_UI_Game_field::Y_Offset = 0;
// ----------------------------------------------------------------------------------------------------
void As_UI_Game_field::Show_Dynamic(bool Color_Mode)       // «десь нельз€ устанавливать цвет при затирке ?
{	
	AsCarriage::Hide();
	auto game_field = As_Game_Field::Game_Field;
	const int n = game_field.size();	
	const int cell_width = 5;  		// ƒл€ €чейки шириной в 4 символа
	
	// ѕечать элементов игрового пол€
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			AsCarriage::Set_Coord(
				As_UI_Game_field::X_Offset + 1 + j * cell_width, 
				As_UI_Game_field::Y_Offset + 1 + i * 2
			);
			
			if (Color_Mode)
			{
				switch (game_field[i][j])      // Color setting
				{
					case 2: 	AsCarriage::Set_Color(EC_Blue);			break;
					case 4:		AsCarriage::Set_Color(EC_Cyan); 		break;
					case 8: 	AsCarriage::Set_Color(EC_Dark_Green);	break;
					case 16: 	AsCarriage::Set_Color(EC_Dark_Grey);	break;
					case 32: 	AsCarriage::Set_Color(EC_Dark_Pink);	break;
					case 64: 	AsCarriage::Set_Color(EC_Dark_Red);		break;
					case 128: 	AsCarriage::Set_Color(EC_Dark_Yellow);	break;
					case 256: 	AsCarriage::Set_Color(EC_Green);		break;
					case 512: 	AsCarriage::Set_Color(EC_Dark_Yellow);	break;
					case 1024: 	AsCarriage::Set_Color(EC_Yellow);		break;
					case 2048: 	AsCarriage::Set_Color(EC_Dark_Blue);	break;
					default:	AsCarriage::Set_Color(EC_Black);		break;   // for 0
				}	
			}
			else
			{
				AsCarriage::Set_Color(EC_Black);
			}
			
			printf("%d", game_field[i][j]);
		}		
	}
}
// ----------------------------------------------------------------------------------------------------
void As_UI_Game_field::Show_Static(bool Color_Mode)
{		
	AsCarriage::Set_Color(Color_Mode ? EC_White : EC_Black);
	
	const int n = As_Game_Field::Game_Field.size();	
	const int cell_width = 5;  							// ƒл€ €чейки шириной в 4 символа
	
	for (int y = 0; y <= n * 2; y ++)
	{   
	    if (y % 2 == 0)
	    {
	    	for (int x = 0; x <= n * cell_width; x ++)
	    	{
	    		AsCarriage::Set_Coord(As_UI_Game_field::X_Offset + x, As_UI_Game_field::Y_Offset + y);
				printf("%c", (x % cell_width == 0) ? '+' : '-');
			}
		}
		else
		{
			for (int x = 0; x <= n; x ++)
			{
				AsCarriage::Set_Coord(As_UI_Game_field::X_Offset + x * cell_width, As_UI_Game_field::Y_Offset + y);
				printf("|");
			}
		}
	}
}
// ----------------------------------------------------------------------------------------------------
void As_UI_Game_field::Set_Draw_Position(int x_offset, int y_offset)
{
	As_UI_Game_field::X_Offset = x_offset;
	As_UI_Game_field::Y_Offset = y_offset;
}




// ----------------------------------------------------------------------------------------------------
int As_UI_System_Msg::X_Offset = 0;
int As_UI_System_Msg::Y_Offset = 0;
// ----------------------------------------------------------------------------------------------------
void As_UI_System_Msg::Show_Dynamic(bool Color_Mode)
{
	AsCarriage::Set_Color(Color_Mode ? EC_White : EC_Black);
	AsCarriage::Set_Coord(As_UI_System_Msg::X_Offset, As_UI_System_Msg::Y_Offset);
	std::cout << As_System_Message::Get();
}
// ----------------------------------------------------------------------------------------------------
void As_UI_System_Msg::Set_Draw_Position(int x_offset, int y_offset)
{
	As_UI_System_Msg::X_Offset = x_offset;
	As_UI_System_Msg::Y_Offset = y_offset;
}




// ----------------------------------------------------------------------------------------------------
int As_UI_Control_Info::X_Offset = 0;
int As_UI_Control_Info::Y_Offset = 0;
// ----------------------------------------------------------------------------------------------------
void As_UI_Control_Info::Set_Draw_Position(int x_offset, int y_offset)
{
	As_UI_Control_Info::X_Offset = x_offset;
	As_UI_Control_Info::Y_Offset = y_offset;
}
// ----------------------------------------------------------------------------------------------------
void As_UI_Control_Info::Show_Static(bool Color_Mode)
{
	AsCarriage::Set_Color(Color_Mode ? EC_White : EC_Black);
	
	AsCarriage::Set_Coord(As_UI_Control_Info::X_Offset, As_UI_Control_Info::Y_Offset);
	printf("Control:");
	AsCarriage::Set_Coord(As_UI_Control_Info::X_Offset, As_UI_Control_Info::Y_Offset + 1);
	printf("  r - records");
	AsCarriage::Set_Coord(As_UI_Control_Info::X_Offset, As_UI_Control_Info::Y_Offset + 2);
	printf("  esc - exit");
	AsCarriage::Set_Coord(As_UI_Control_Info::X_Offset, As_UI_Control_Info::Y_Offset + 3);
	printf("  arrows - move");
}




// ----------------------------------------------------------------------------------------------------
int As_UI_Total_Score::X_Offset = 0;
int As_UI_Total_Score::Y_Offset = 0;
// ----------------------------------------------------------------------------------------------------
void  As_UI_Total_Score::Set_Draw_Position(int x_offset, int y_offset)
{
	As_UI_Total_Score::X_Offset = x_offset;
	As_UI_Total_Score::Y_Offset = y_offset;
}
// ----------------------------------------------------------------------------------------------------
void As_UI_Total_Score::Show_Static(bool Color_Mode)
{
	AsCarriage::Set_Color(Color_Mode ? EC_White : EC_Black);
	AsCarriage::Set_Coord(As_UI_Total_Score::X_Offset, As_UI_Total_Score::Y_Offset);
	printf("Score:");
}
// ----------------------------------------------------------------------------------------------------
void As_UI_Total_Score::Show_Dynamic(bool Color_Mode)
{
	AsCarriage::Set_Color(Color_Mode ? EC_White : EC_Black);
	AsCarriage::Set_Coord(As_UI_Total_Score::X_Offset + 8, As_UI_Total_Score::Y_Offset);
			
	std::vector<int> score_data	= As_Total_Score::Get();
			
	printf("%d  ", score_data[0]);
	
	if (score_data.size() == 2)
		printf("+%d", score_data[1]);
}
