#include "Event.hpp"
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
	As_Game_Field::Offset(offset_direction);   // смещение матрицы в зависимости от направления
	
	if (As_Game_Field::Offset_Has_Been)     // если смещение произошло   - перепечатываем матрицу 
	{
		As_Game_Field::Put_Element();   // если на матрице есть нули, установка 2 и 4			
		As_UI_Game_field::Hide();   // затираем дин. часть интерфейса
		As_UI_Game_field::Show();   // печатаем новое состояние матрицы
	}
	
	if (As_Game_Field::Offset_Is_Not_Possible)   // обработка проигрыша
	    printf("\nFail");
	    
	else if (As_Game_Field::Have_2048)   // обработка выигрыша
	    printf("\nWin");
}




