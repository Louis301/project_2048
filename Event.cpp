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
	//смещение плиток со сложением чисел
	//проверка наличия 2048 или невозможности хода
	//сохраняем результат в таблицу рекордов
	//печать соответствующего системного сообщения
	As_Game_Field::Offset(offset_direction);
	As_UI_Game_field::Hide();
	As_UI_Game_field::Show();
}
