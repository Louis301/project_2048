#pragma once 
#include <vector>
#include <string>

enum EOffsetDirection 
{
	EOD_To_Left,
	EOD_To_Right,
	EOD_To_Up,
	EOD_To_Down
};


class As_Game_Field
{	
	public:
		static void Reset();  // —брасывает состо€ние игрового до исходного
		static void Offset(EOffsetDirection offset_direction);  // —мещает элементы игрового пол€
//		Get_Offset_Indicators
		static void Put_Element();  // установка простого элемента на свободную €чейку
//		static bool Offset_Is_Not_Possible();
		
		static std::vector<std::vector<int>> Game_Field;   // —писок списков целочисленных элементов
		static std::vector<int> Offset_Indicators;
		static bool Have_2048;
		static bool Offset_Has_Been;
		
	private:
		static void Line_Elements_Offset(std::vector<int> &line, int delta_offset);
		static void Reverse();  // »нверси€ матрицы относительно главной диагонали
//		static void Set_Offset_Indicators(EOffsetDirection offset_direction);
		
//		static bool Check_Possible_Offset_Full_Indicator;
		static const int N;
};


class As_System_Message
{
	private:
		static std::string System_Msg;
		
	public:
		static void Reset();  // —брасывает состо€ние системного сообщени€ до нулевого
		static void Set(std::string message);
};


class As_Total_Score
{
	private:
		static int Total_Score;
	
	public:
		static void Reset();  // —брасывает счЄт до нулевого
};


class As_Record_Table
{
	public:
		static void Reset();
};
