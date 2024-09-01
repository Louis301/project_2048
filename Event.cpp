#include "Event.hpp"
#include "User_Interface.hpp"
#include "Record_Table.hpp"
#include "Program.hpp"
#include "Total_Score.hpp"
#include "System_Message.hpp"
#include "Game_Field.hpp"

// ----------------------------------------------------------------------------------------------------
void As_Event::Stop_Program()
{
	As_Program::Exit_Program = true;
	AsCarriage::Set_Coord(0, 2 * As_Game_Field::Game_Field.size() + 2);
	AsCarriage::Set_Color(EC_White);
	As_Record_Table::Add_Record(As_Total_Score::Total_Score);
}
// ----------------------------------------------------------------------------------------------------
void As_Event::Continue_Game()
{
	if (As_Program::Get_Interaction_Layer() == EIL_Viewing_Results)
	{
		system("cls");      // ��������� ��������� ������
		As_UI_Game_field::Show_Static(true);
		As_UI_Game_field::Show_Dynamic(true);
		As_UI_Total_Score::Show_Static(true);
		As_UI_Total_Score::Show_Dynamic(true);
		As_UI_Control_Info::Show_Static(true);	
	}
	else
	{
		As_UI_System_Msg::Show_Dynamic(false);  //������� ��������� ���������
	}
	
	As_Program::Set_Interaction_Layer(EIL_Matrix_Management);
}
// ----------------------------------------------------------------------------------------------------
void As_Event::Restart_Game()
{
	As_Program::Set_Interaction_Layer(EIL_Matrix_Management);
	
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
void As_Event::You_Win()
{
	As_Record_Table::Add_Record(As_Total_Score::Total_Score);
	As_Program::Set_Interaction_Layer(EIL_Winning);
	As_UI_System_Msg::Set_Draw_Position(0, 2 * As_Game_Field::Game_Field.size() + 2);
	As_System_Message::Set("YOU WIN !!!  Press C for continue");
	As_UI_System_Msg::Set_Color(EC_Yellow);
	As_Game_Field::Have_2048 = false;        // ����� � ���������� ��������� �� ����������
	As_UI_System_Msg::Show_Dynamic(true);    
}
// ----------------------------------------------------------------------------------------------------
void As_Event::You_Fail()
{
	As_Record_Table::Add_Record(As_Total_Score::Total_Score);
	As_Program::Set_Interaction_Layer(EIL_Losing);
	As_UI_System_Msg::Set_Draw_Position(0, 2 * As_Game_Field::Game_Field.size() + 2);
	As_System_Message::Set("You Fail...  Press R for reload");
	As_UI_System_Msg::Set_Color(EC_Red);
	As_Game_Field::Offset_Is_Not_Possible = false;   // ����� � ���������� ��������� �� ����������
	As_UI_System_Msg::Show_Dynamic(true);
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
		As_Event::You_Fail();
		
	if (As_Game_Field::Have_2048)   // ��������� ��������
		As_Event::You_Win();
		
	As_UI_Game_field::Show_Dynamic(true);   // �������� ����� ��������� �������	
	As_UI_Total_Score::Show_Dynamic(true);   // �������� ����� ��������� �����
}
// ----------------------------------------------------------------------------------------------------
void As_Event::Record_Table_Interaction()
{
	system("cls");
	As_Program::Set_Interaction_Layer(EIL_Viewing_Results);
	As_UI_Record_Table::Set_Draw_Position(0, 0);
	As_UI_Record_Table::Show_Static(true);
}
