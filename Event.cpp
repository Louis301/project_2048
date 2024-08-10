#include "Event.hpp"
//#include "InternalData.hpp"
#include "User_Interface.hpp"
#include "Program.hpp"

void As_Event::Stop_Program()
{
	As_Program::Exit_Program = true;
}


void As_Event::Show_Record_Table()
{
	//стирает главный экран
	//отображает таблицу рекордов
	//отображает клавиши управления экраном
}


void As_Event::Continue_Game()
{
	//убираем сообщение о победе (очистка системного сообщения)
	//передаём пользователю управление игровой матрицей
}


void As_Event::Restart_Game()
{
	//очищаем системное сообщение
	//обновляем счёт
	//обновляем игровое поле
	//передаём пользователю управление игровой матрицей
}



void As_Event::Game_Field_Interaction(EOffsetDirection offset_direction)
{
//	printf("kjj");
	if (As_Game_Field::Offset_Indicators[offset_direction] == 0)
	{
		As_Game_Field::Offset(offset_direction);
		As_UI_Game_field::Hide();
		As_UI_Game_field::Show();  // Заменить на отображение динамической части
		
		As_Game_Field::Put_Element();
	}
//	if (As_Game_Field::Offset_Is_Not_Possible())
//		printf("\nFail");
//	else if (As_Game_Field::Have_2048)
//		printf("\nWin");
//	else
//		As_Game_Field::Put_Element();
}





