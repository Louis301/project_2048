#pragma once 
#include <vector>
#include <string>

// ----------------------------------------------------------------------------------------------------
enum EOffsetDirection 
{
	EOD_To_Left,
	EOD_To_Right,
	EOD_To_Up,
	EOD_To_Down
};




// ----------------------------------------------------------------------------------------------------
class As_Game_Field
{	
	public:
		static void Reset();  // ���������� ��������� �������� �� ���������
		static void Offset(EOffsetDirection offset_direction);  // ������� �������� �������� ����
		static void Put_Element();  // ��������� �������� �������� �� ��������� ������
		
		static bool Offset_Has_Been;
		static bool Offset_Is_Not_Possible;
		static bool Have_2048;
		
		static std::vector<std::vector<int>> Game_Field;   // ������ ������� ������������� ���������]
		
	private:
		static void Line_Elements_Offset(std::vector<int> &line, int delta_offset);
		static void Reverse();  // �������� ������� ������������ ������� ���������
		
		static int Delta_Score;        // ���� ������� � ����� ������� �� ���������
		
		static std::vector<bool> Offset_Indicators;
		static const int N;
};
// ----------------------------------------------------------------------------------------------------
class As_System_Message
{
	private:
		static std::string System_Msg;
		
	public:
		static void Reset();  // ���������� ��������� ���������� ��������� �� ��������
		static void Set(std::string message);
		static std::string Get();
		
};
// ----------------------------------------------------------------------------------------------------
class As_Total_Score
{
	private:
		static int Total_Score;
		static int Delta_Score;
	
	public:	
		static void Reset();  					// ���������� ���� �� ��������
		static void Set(int delta_score);       // �������� �� ��������� (�� ������)  
		static std::vector<int> Get();
};
// ----------------------------------------------------------------------------------------------------
class As_Record_Table
{
	public:
		static void Reset();
};
