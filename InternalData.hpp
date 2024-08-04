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
		static void Reset();  // Сбрасывает состояние игрового до исходного
		static void Offset(EOffsetDirection offset_direction);  // Смещает элементы игрового поля
//		static std::vector<std::vector<int>> Get();
		
		static const int N;
		static std::vector<std::vector<int>> Game_Field;   // Список списков целочисленных элементов
		
	private:
		static void Line_Elements_Offset(std::vector<int> line, int delta_offset);
		static void Reverse();  // Инверсия матрицы относительно главной диагонали
};


class As_System_Message
{
	private:
		static std::string System_Msg;
		
	public:
		static void Reset();  // Сбрасывает состояние системного сообщения до нулевого
		static void Set(std::string message);
};


class As_Total_Score
{
	private:
		static int Total_Score;
	
	public:
		static void Reset();  // Сбрасывает счёт до нулевого
};


class As_Record_Table
{
	public:
		static void Reset();
};
