#include "User_Interface.hpp"
#include "InternalData.hpp"

void As_UI_Game_field::Show()
{
	auto game_field = As_Game_Field::Game_Field;
	
	for (int i = 0; i < game_field.size(); i++)
	{
		for (int j = 0; j < game_field.size(); j++)
		{
			printf("%d\t", game_field[i][j]);
		}
		printf("\n");
		
	}
}

void As_UI_System_Msg::Show()
{
	printf("System_Msg");
}

void As_UI_Control_Info::Show()
{

}

void As_UI_Total_Score::Show()
{
}
