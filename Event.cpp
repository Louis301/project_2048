#include "Event.hpp"
#include "User_Interface.hpp"
#include "Program.hpp"

// ----------------------------------------------------------------------------------------------------
void As_Event::Stop_Program()
{
	As_Program::Exit_Program = true;
	AsCarriage::Set_Coord(0, 2 * As_Game_Field::Game_Field.size() + 3);
	AsCarriage::Set_Color(EC_White);
}
// ----------------------------------------------------------------------------------------------------
void As_Event::Show_Record_Table()
{
	//стирает главный экран
	//отображает таблицу рекордов
	//отображает клавиши управлени€ экраном
}
// ----------------------------------------------------------------------------------------------------
void As_Event::Continue_Game()
{
	//убираем сообщение о победе (очистка системного сообщени€)
	//передаЄм пользователю управление игровой матрицей
}
// ----------------------------------------------------------------------------------------------------
void As_Event::Restart_Game()
{
	As_UI_Game_field::Show_Dynamic(false);  // затираем дин. часть интерфейса
	As_UI_Total_Score::Show_Dynamic(false);
	As_UI_System_Msg::Show_Dynamic(false);  //очищаем системное сообщение
	
	As_Total_Score::Reset();  //обновл€ем счЄт
	As_Game_Field::Reset();   //обновл€ем игровое поле
	As_System_Message::Reset();   								// не сбрасываетс€ !!  ¬≈–Ќ”“№—я ѕќ«∆≈
	
	As_UI_Game_field::Show_Dynamic(true);  // затираем дин. часть интерфейса
	As_UI_Total_Score::Show_Dynamic(true);
}
// ----------------------------------------------------------------------------------------------------
void As_Event::Game_Field_Interaction(EOffsetDirection offset_direction)
{	
	As_UI_Game_field::Show_Dynamic(false);  // затираем дин. часть интерфейса
	As_UI_Total_Score::Show_Dynamic(false);
	
	As_Game_Field::Offset(offset_direction);   // смещение матрицы в зависимости от направлени€     
	if (As_Game_Field::Offset_Has_Been)     // если смещение произошло   - перепечатываем матрицу 
		As_Game_Field::Put_Element();   // если на матрице есть нули, установка 2 и 4			
	
	if (As_Game_Field::Offset_Is_Not_Possible)   // обработка проигрыша
	{
		As_System_Message::Set("You Fail...");
		As_UI_System_Msg::Set_Color(EC_Red);
	}
	if (As_Game_Field::Have_2048)   // обработка выигрыша
	{
		As_System_Message::Set("YOU WIN !!!");
		As_UI_System_Msg::Set_Color(EC_Yellow);
	}
	
	As_UI_Game_field::Show_Dynamic(true);   // печатаем новое состо€ние матрицы	
	As_UI_Total_Score::Show_Dynamic(true);   // печатаем новое состо€ние счЄта
	As_UI_System_Msg::Show_Dynamic(true);
}


