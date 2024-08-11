#include "User_Interface.hpp"
#include "InternalData.hpp"
#include "Carriage.hpp"
#include <iostream> 

#include <windows.h>
#include <conio.h>

void As_UI_Game_field::Show()
{
	
	
	AsCarriage::Set_Default();
	
	auto game_field = As_Game_Field::Game_Field;
	int n = game_field.size();
	
	// Печать элементов игрового поля
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			switch (game_field[i][j])
			{
				case 2: 
					AsCarriage::Set_Color(EC_Blue);
					break;
				case 4:
					AsCarriage::Set_Color(EC_Cyan); 
					break;
				case 8: 
					AsCarriage::Set_Color(EC_Dark_Green);
					break;
				case 16: 
					AsCarriage::Set_Color(EC_Dark_Grey);
					break;
				case 32: 
					AsCarriage::Set_Color(EC_Dark_Pink);
					break;
				case 64: 
					AsCarriage::Set_Color(EC_Dark_Red);
					break;
				case 128: 
					AsCarriage::Set_Color(EC_Dark_Yellow);
					break;
				case 256: 
					AsCarriage::Set_Color(EC_Green);
					break;
				case 512: 
					AsCarriage::Set_Color(EC_Dark_Yellow);
					break;
				case 1024: 
					AsCarriage::Set_Color(EC_Yellow);
					break;
				case 2024: 
					AsCarriage::Set_Color(EC_Dark_Blue);	
					break;
				default:
					AsCarriage::Set_Color(EC_Black);	
					break;
			}
			printf("%d\t", game_field[i][j]);
		}		
		printf("\n");	
	}
}

void As_UI_Game_field::Hide()
{
	AsCarriage::Set_Color(EC_Black, EC_Black);
	As_UI_Game_field::Show();
}

// -----------------------------------------------------------
void As_UI_System_Msg::Show()
{
}

void As_UI_Control_Info::Show()
{
}

void As_UI_Total_Score::Show()
{
}
