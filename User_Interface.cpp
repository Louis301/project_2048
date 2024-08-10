#include "User_Interface.hpp"
#include "InternalData.hpp"
#include "Carriage.hpp"

#include <iostream> 

void As_UI_Game_field::Show()
{
	AsCarriage::Set_Default();
//	AsCarriage::Set_Coord(0, 0);
//	AsCarriage::Set_Color(EC_White, EC_Black);
	
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
	
//	std::cout << "\nOffset_Is_Not_Possible -> " << As_Game_Field::Offset_Is_Not_Possible();
	std::cout << "\nHave_2048 -> " << As_Game_Field::Have_2048;
	
	std::cout << "\n\nto_left -> " << As_Game_Field::Offset_Indicators[0];
	std::cout << "\nto_right -> " << As_Game_Field::Offset_Indicators[1];
	std::cout << "\nto_up -> " << As_Game_Field::Offset_Indicators[2];
	std::cout << "\nto_down -> " << As_Game_Field::Offset_Indicators[3];
	
//	std::cout << "\n\nOffset_Has_Been -> " << As_Game_Field::Offset_Has_Been;
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
