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
	//������� ������� �����
	//���������� ������� ��������
	//���������� ������� ���������� �������
}
// ----------------------------------------------------------------------------------------------------
void As_Event::Continue_Game()
{
	//������� ��������� � ������ (������� ���������� ���������)
	//������� ������������ ���������� ������� ��������
}
// ----------------------------------------------------------------------------------------------------
void As_Event::Restart_Game()
{
	As_UI_Game_field::Show_Dynamic(false);  // �������� ���. ����� ����������
	As_UI_Total_Score::Show_Dynamic(false);
	As_UI_System_Msg::Show_Dynamic(false);  //������� ��������� ���������
	
	As_Total_Score::Reset();  //��������� ����
	As_Game_Field::Reset();   //��������� ������� ����
	As_System_Message::Reset();   								// �� ������������ !!  ��������� �����
	
	As_UI_Game_field::Show_Dynamic(true);  // �������� ���. ����� ����������
	As_UI_Total_Score::Show_Dynamic(true);
}
// ----------------------------------------------------------------------------------------------------
void As_Event::Game_Field_Interaction(EOffsetDirection offset_direction)
{	
	As_UI_Game_field::Show_Dynamic(false);  // �������� ���. ����� ����������
	As_UI_Total_Score::Show_Dynamic(false);
	
	As_Game_Field::Offset(offset_direction);   // �������� ������� � ����������� �� �����������     
	if (As_Game_Field::Offset_Has_Been)     // ���� �������� ���������   - �������������� ������� 
		As_Game_Field::Put_Element();   // ���� �� ������� ���� ����, ��������� 2 � 4			
	
	if (As_Game_Field::Offset_Is_Not_Possible)   // ��������� ���������
	{
		As_System_Message::Set("You Fail...");
		As_UI_System_Msg::Set_Color(EC_Red);
	}
	if (As_Game_Field::Have_2048)   // ��������� ��������
	{
		As_System_Message::Set("YOU WIN !!!");
		As_UI_System_Msg::Set_Color(EC_Yellow);
	}
	
	As_UI_Game_field::Show_Dynamic(true);   // �������� ����� ��������� �������	
	As_UI_Total_Score::Show_Dynamic(true);   // �������� ����� ��������� �����
	As_UI_System_Msg::Show_Dynamic(true);
}


