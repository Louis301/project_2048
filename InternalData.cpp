#include "InternalData.hpp"
#include "CSVFile.hpp"

const int As_Game_Field::N = 4;  // Порядок игровой матрицы
std::vector<std::vector<int>> As_Game_Field::Game_Field;


void As_Game_Field::Reset()
{
	for (int i = 0; i < N; i++)
	{
		std::vector<int> line;
		for (int j = 0; j < N; j++)
			line.push_back(0);
		Game_Field.push_back(line);
	}
	
	// Для установке первичного состояния игрового поля (с двумя элементами)
	const std::vector<int> simple_elements = {2, 4};
	
	for (int i = 0; i < 2; i++)  // Число ячеек для первичной установки
	{
		int x = rand() % N;
		int y = rand() % N;				
		
		if (Game_Field[y][x] == 0) 
			Game_Field[y][x] = simple_elements[rand() % 2];
	}
}

//std::vector<std::vector<int>> As_Game_Field::Get()
//{
//	return Game_Field;
//}

void As_Game_Field::Line_Elements_Offset(std::vector<int> line, int delta_offset) 
{
}

void As_Game_Field::Reverse()
{
}

void As_Game_Field::Offset(EOffsetDirection offset_direction)
{
}


// ---------------------------------------------------------------------
void As_System_Message::Reset()
{
}

void As_System_Message::Set(std::string message)
{
}


// ---------------------------------------------------------------------
void As_Total_Score::Reset()
{	
}


void As_Record_Table::Reset()
{
	// control tabel logic
}

