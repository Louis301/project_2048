#include "User_Interface.hpp"
#include "InternalData.hpp"
#include "Carriage.hpp"

void As_UI_Game_field::Show()
{
	AsCarriage::Set_Coord(0, 0);
	AsCarriage::Set_Color(EC_White, EC_Black);
	
	auto game_field = As_Game_Field::Game_Field;
	int n = game_field.size();
	
	
	// Печать рамки
	// ...
	
	
	// Печать элементов игрового поля
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			printf("%d\t", game_field[i][j]);
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
