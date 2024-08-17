#include "Event.hpp"
#include "User_Interface.hpp"
#include "Program.hpp"

// ----------------------------------------------------------------------------------------------------
void As_Event::Stop_Program()
{
	As_Program::Exit_Program = true;
	AsCarriage::Set_Coord(0, 2 * As_Game_Field::Game_Field.size() + 1);
	AsCarriage::Set_Color(EC_White);
}
// ----------------------------------------------------------------------------------------------------
void As_Event::Show_Record_Table()
{
	//стирает главный экран
	//отображает таблицу рекордов
	//отображает клавиши управления экраном
}
// ----------------------------------------------------------------------------------------------------
void As_Event::Continue_Game()
{
	//убираем сообщение о победе (очистка системного сообщения)
	//передаём пользователю управление игровой матрицей
}
// ----------------------------------------------------------------------------------------------------
void As_Event::Restart_Game()
{
	//очищаем системное сообщение
	//обновляем счёт
	//обновляем игровое поле
	//передаём пользователю управление игровой матрицей
}
// ----------------------------------------------------------------------------------------------------
void As_Event::Game_Field_Interaction(EOffsetDirection offset_direction)
{	
	As_UI_Game_field::Show_Dynamic(false);  // затираем дин. часть интерфейса
	As_UI_Total_Score::Show_Dynamic(false);
	
	As_Game_Field::Offset(offset_direction);   // смещение матрицы в зависимости от направления     
	
	if (As_Game_Field::Offset_Has_Been)     // если смещение произошло   - перепечатываем матрицу 
		As_Game_Field::Put_Element();   // если на матрице есть нули, установка 2 и 4			
	
	As_UI_Game_field::Show_Dynamic(true);   // печатаем новое состояние матрицы	
	As_UI_Total_Score::Show_Dynamic(true);   // печатаем новое состояние счёта
	
	if (As_Game_Field::Offset_Is_Not_Possible)   // обработка проигрыша
	{
		As_System_Message::Set("You Fail...");
		As_UI_System_Msg::Show_Dynamic(true);
	}
	    
	if (As_Game_Field::Have_2048)   // обработка выигрыша
	{
		As_System_Message::Set("YOU WIN !!!");
		As_UI_System_Msg::Show_Dynamic(true);
	}
}


