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
	//������� ������� �����
	//���������� ������� ��������
	//���������� ������� ���������� �������
}


void As_Event::Continue_Game()
{
	//������� ��������� � ������ (������� ���������� ���������)
	//������� ������������ ���������� ������� ��������
}


void As_Event::Restart_Game()
{
	//������� ��������� ���������
	//��������� ����
	//��������� ������� ����
	//������� ������������ ���������� ������� ��������
}


void As_Event::Game_Field_Interaction(EOffsetDirection offset_direction)
{
	//�������� ������ �� ��������� �����
	//�������� ������� 2048 ��� ������������� ����
	//��������� ��������� � ������� ��������
	//������ ���������������� ���������� ���������
	As_Game_Field::Offset(offset_direction);
	As_UI_Game_field::Hide();
	As_UI_Game_field::Show();
}
