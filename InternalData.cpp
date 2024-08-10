#include "InternalData.hpp"
#include <algorithm>


bool As_Game_Field::Offset_Has_Been = false;
bool As_Game_Field::Have_2048 = false;
//bool As_Game_Field::Check_Possible_Offset_Full_Indicator = false;

const int As_Game_Field::N = 4;  // ѕор€док игровой матрицы

std::vector<std::vector<int>> As_Game_Field::Game_Field;
std::vector<int> As_Game_Field::Offset_Indicators = {0, 0, 0, 0};


void As_Game_Field::Reset()
{
	for (int i = 0; i < N; i++)
	{
		std::vector<int> line;
		for (int j = 0; j < N; j++)
			line.push_back(0);
		Game_Field.push_back(line);
	}
	
	// ƒл€ установке первичного состо€ни€ игрового пол€ (с двум€ элементами)
	Put_Element();
	Put_Element();
}

void As_Game_Field::Put_Element()
{
	const std::vector<int> simple_elements = {2, 4};
	int x = rand() % N;
	int y = rand() % N;				
		
	if (Game_Field[y][x] == 0) 
		Game_Field[y][x] = simple_elements[rand() % 2];
}

void As_Game_Field::Line_Elements_Offset(std::vector<int> &line, int delta_offset) 
{
	int i = (delta_offset == -1) ? (i = N - 1) : (0);
    int j = i + delta_offset;	
    
    Offset_Has_Been = false;
    
	while ((delta_offset == -1) ? (i > 0 && j >= 0) : (i < N - 1 && j < N))
    {
    	if (line[j] == 0)
    	{
    		j += delta_offset;
		}
        else if (line[j] == line[i])   // здесь проверка возможности след. хода
        {
        	line[i] *= 2;
            i += delta_offset;
            line[j] = 0;
            j = i + delta_offset;
			Offset_Has_Been = true;
			
			if (line[i] == 64)   // «аменить на 2048
				Have_2048 = true;
		}
        else if (line[i] == 0)    // здесь проверка возможности след. хода
        {
        	int temp = line[i];
        	line[i] = line[j];
        	line[j] = temp;
            j += delta_offset;
            Offset_Has_Been = true;
		}    
        else
        {
        	i += delta_offset;
            j = i + delta_offset;
		}
	}
}

void As_Game_Field::Reverse()
{
	int k = 0;
	for (int i = 0; i < N; i++)
	{
		k ++;
		for (int j = 0; j < k; j++)
		{
			int temp = Game_Field[i][j];
			Game_Field[i][j] = Game_Field[j][i];
			Game_Field[j][i] = temp;
		}
	}
}

void As_Game_Field::Offset(EOffsetDirection offset_direction)
{
	bool vertical_offset = false;
	int delta_offset = 1;
//	Offset_Has_Been = false;
    
//	if (!Check_Possible_Offset_Full_Indicator)
    	Offset_Indicators = {0, 0, 0, 0};
	
	if (offset_direction == EOD_To_Down || offset_direction == EOD_To_Up)
        vertical_offset = true;
    if (offset_direction == EOD_To_Right || offset_direction == EOD_To_Down)
        delta_offset = -1;
               
    if (vertical_offset)  
		Reverse();
               
    for (auto &line : Game_Field)
    	Line_Elements_Offset(line, delta_offset);
    
	if (vertical_offset)  
		Reverse();
	
	Offset_Indicators[offset_direction] = (int)(!Offset_Has_Been);
}


//bool As_Game_Field::Offset_Is_Not_Possible()
//{
//	Check_Possible_Offset_Full_Indicator = true;
//		
////	std::vector<std::vector<int>> gf;
////	for (auto line : Game_Field)
////		gf.push_back(line);
//	auto gf = Game_Field;
//	 
////	bool Not_Possible = false;
////	
//	Offset(EOD_To_Up);
//	if (Offset_Has_Been)
//	{
//		Check_Possible_Offset_Full_Indicator = false;
//		Game_Field = gf;
//		return false;
//	}
////		
//	Offset(EOD_To_Down);
//	if (Offset_Has_Been)
//	{
//		Check_Possible_Offset_Full_Indicator = false;
//		Game_Field = gf;
//		return false;
//	}
////	
//	Offset(EOD_To_Left);
//	if (Offset_Has_Been)
//	{
//		Check_Possible_Offset_Full_Indicator = false;
//		Game_Field = gf;
//		return false;
//	}
////		
//	Offset(EOD_To_Right);
//	if (Offset_Has_Been)
//	{
//		Check_Possible_Offset_Full_Indicator = false;
//		Game_Field = gf;
//		return false;
//	}
////		
//	return true;
//}


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

