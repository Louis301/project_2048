#include "InternalData.hpp"
//#include "CSVFile.hpp"

const int As_Game_Field::N = 4;  // ѕор€док игровой матрицы
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
	
	// ƒл€ установке первичного состо€ни€ игрового пол€ (с двум€ элементами)
	const std::vector<int> simple_elements = {2, 4};
	
	for (int i = 0; i < 2; i++)  // „исло €чеек дл€ первичной установки
	{
		int x = rand() % N;
		int y = rand() % N;				
		
		if (Game_Field[y][x] == 0) 
			Game_Field[y][x] = simple_elements[rand() % 2];
	}
}

void As_Game_Field::Line_Elements_Offset(std::vector<int> &line, int delta_offset) 
{
	int i = (delta_offset == -1) ? (i = N - 1) : (0);
    int j = i + delta_offset;
    
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
		}
        else if (line[i] == 0)    // здесь проверка возможности след. хода
        {
        	int temp = line[i];
        	line[i] = line[j];
        	line[j] = temp;
            j += delta_offset;
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

