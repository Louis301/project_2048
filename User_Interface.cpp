#include "User_Interface.hpp"
#include "InternalData.hpp"
#include "Carriage.hpp"
#include <iostream> 

#include <windows.h>
#include <conio.h>

void As_UI_Game_field::Show()
{
	AsCarriage::Hide();
	
	Show_Static();
	Show_Dynamic();
	
	//printf("jj");
	
}

void As_UI_Game_field::Show_Dynamic()
{	
	auto game_field = As_Game_Field::Game_Field;
	
	const int n = game_field.size();	
	const int cell_width = 5;  		// Для ячейки шириной в 4 символа
	
	// Печать элементов игрового поля
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			AsCarriage::Set_Coord(1 + j * cell_width, 1 + i * 2);
			
			switch (game_field[i][j])
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
			
			printf("%d", game_field[i][j]);
		}		
	}
	
//	1    0
//	3    1
//	5    2
//	7    3
//	
//	1 + i * 2
	
	
	//  00 01 02 03
	//  10 11 12 13
	//  20 21 22 23
	//  30 31 32 33
	
//	+----+----+----+----+
//	|    |    |    |    |
//	
//	0,1  4,1  8,1  12,1  16,1 
	
}

void As_UI_Game_field::Show_Static()
{
	AsCarriage::Set_Color(EC_White, EC_Black);
	
	const int n = As_Game_Field::Game_Field.size();	
	const int cell_width = 5;  							// Для ячейки шириной в 4 символа
	
	for (int y = 0; y <= n * 2; y ++)
	{   
	    if (y % 2 == 0)
	    {
	    	for (int x = 0; x <= n * cell_width; x ++)
	    	{
	    		AsCarriage::Set_Coord(x, y);
				printf("%c", (x % cell_width == 0) ? '+' : '-');
			}
		}
		else
		{
			for (int x = 0; x <= n; x ++)
			{
				AsCarriage::Set_Coord(x * cell_width, y);
				printf("|");
			}
		}
	}
}

void As_UI_Game_field::Hide_Dynamic()                       // нужно печатать элементы матрицы чёрным на чёрном !!!
{
	AsCarriage::Set_Color(EC_Black, EC_Black);
	//As_UI_Game_field::Show_Dynamic();              // Печать дин. части UI-component
	
	
	auto game_field = As_Game_Field::Game_Field;
	
	const int n = game_field.size();	
	const int cell_width = 5;  		// Для ячейки шириной в 4 символа
	
	// Печать элементов игрового поля
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			AsCarriage::Set_Coord(1 + j * cell_width, 1 + i * 2);
			
			printf("####");
		}		
	}
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
