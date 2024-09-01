#pragma once 
#include <vector>

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
		static void Reset();  // —брасывает состо€ние игрового до исходного
		static void Offset(EOffsetDirection offset_direction);  // —мещает элементы игрового пол€
		static void Put_Element();  // установка простого элемента на свободную €чейку
		
		static bool Offset_Is_Not_Possible;
		static bool Have_2048;
		static bool Offset_Has_Been;
		
		static std::vector<std::vector<int>> Game_Field;   // —писок списков целочисленных элементов]
		
	private:
		static void Line_Elements_Offset(std::vector<int> &line, int delta_offset);
		static void Reverse();  // »нверси€ матрицы относительно главной диагонали
		
		static bool Win_Was_Been;
		static std::vector<bool> Offset_Indicators;
		static const int N;
};
