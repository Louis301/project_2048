#include "InternalData.hpp"
#include <time.h>
#include <ctime>
#include <algorithm>
#include <fstream>

bool As_Game_Field::Offset_Has_Been;
bool As_Game_Field::Have_2048;
bool As_Game_Field::Offset_Is_Not_Possible;
bool As_Game_Field::Win_Was_Been;

std::vector<std::vector<int>> As_Game_Field::Game_Field;
std::vector<bool> As_Game_Field::Offset_Indicators;

const int As_Game_Field::N = 5;  // Порядок игровой матрицы

// ----------------------------------------------------------------------------------------------------
void As_Game_Field::Reset()
{
	As_Game_Field::Game_Field.clear();
	As_Game_Field::Offset_Indicators = {true, true, true, true};
	As_Game_Field::Offset_Has_Been = false;
	As_Game_Field::Have_2048 = false;
	As_Game_Field::Offset_Is_Not_Possible = false;
	As_Game_Field::Win_Was_Been = false;
	
	for (int i = 0; i < N; i++)
	{
		std::vector<int> line;
		for (int j = 0; j < N; j++)
			line.push_back(0);
		Game_Field.push_back(line);
	}
	Put_Element();
	Put_Element();
}
// ----------------------------------------------------------------------------------------------------
void As_Game_Field::Put_Element()   // если на матрице есть нули, установка 2 и 4
{
	srand(time(NULL));
	
	for (auto line : Game_Field)
	{
	 	for (auto item : line)
		{
		 	if (item == 0)    // матрица содержит нули
		 	{
		 		const std::vector<int> simple_elements = {2, 4};
		    	int x, y;
		        do
				{
				    x = rand() % N;
				    y = rand() % N;					
				}
				while (Game_Field[y][x] != 0);				
				Game_Field[y][x] = simple_elements[rand() % 2];
				return;
			}
	    }	
	}
}
// ----------------------------------------------------------------------------------------------------
void As_Game_Field::Line_Elements_Offset(std::vector<int> &line, int delta_offset)   // смещение элементов ряда
{
	bool offset_has_been = false;    // проверка смещения (local var)
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
			As_Total_Score::Save_Up(line[i]);   // ВЕРНУТЬСЯ ПОЗЖЕ   здесь надо дельту накапливать			
			
			if (line[i] == 2048 and !Win_Was_Been)      // для обработки выигрыша      ВЕРНУТЬ 2048
				Win_Was_Been = Have_2048 = true;
			
			i += delta_offset;
            line[j] = 0;
            j = i + delta_offset;
			offset_has_been = true;
		}
        else if (line[i] == 0)    // здесь проверка возможности след. хода
        {
        	int temp = line[i];
        	line[i] = line[j];
        	line[j] = temp;
            j += delta_offset;
            offset_has_been = true;
		}    
        else
        {
        	i += delta_offset;
            j = i + delta_offset;
		}
	}	
	if (offset_has_been and !Offset_Has_Been)
		Offset_Has_Been = true;	
}
// ----------------------------------------------------------------------------------------------------
void As_Game_Field::Reverse()    // инверсия матрицы относительно главной диагонали
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
// ----------------------------------------------------------------------------------------------------
void As_Game_Field::Offset(EOffsetDirection offset_direction)   // полное смещение матрицы в выбранном направлении
{	
	Offset_Has_Been = false;   // пока неизвестно, что элементы могут смещены. Поэтому false
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
	
	// здесь известно, прошло смещение в конкретном направлении или нет, а также содержит матрица 2048 или нет
	Offset_Indicators[offset_direction] = Offset_Has_Been;
	
	// если в векторе индикаторов нет единицы  - смещение невозможно
	for (auto item : Offset_Indicators)
		if (item == true)
			return;
	Offset_Is_Not_Possible = true;
}




// ----------------------------------------------------------------------------------------------------
std::string As_System_Message::System_Msg = "";
// ----------------------------------------------------------------------------------------------------
void As_System_Message::Reset() { As_System_Message::Set(""); }
// ----------------------------------------------------------------------------------------------------
void As_System_Message::Set(std::string message) { As_System_Message::System_Msg = message; }
// ----------------------------------------------------------------------------------------------------
std::string As_System_Message::Get() { return As_System_Message::System_Msg; }




// ---------------------------------------------------------------------    Всё переделать !
int As_Total_Score::Total_Score = 0;
int As_Total_Score::Delta_Score = 0;
// ---------------------------------------------------------------------
void As_Total_Score::Reset() 
{ 
	As_Total_Score::Total_Score = 0; 
}
// ---------------------------------------------------------------------
void As_Total_Score::Save_Up(int value)    // ВРЕМЕННО
{ 
	As_Total_Score::Delta_Score = value;
	//As_Total_Score::Total_Score += As_Total_Score::Delta_Score; 
	As_Total_Score::Total_Score += value;
}
// ---------------------------------------------------------------------
void As_Total_Score::Reset_Delta() 
{ 
	As_Total_Score::Delta_Score = 0; 
}
// ---------------------------------------------------------------------
void As_Total_Score::Delta_Increment(int value) 
{ 
	As_Total_Score::Delta_Score += value; 
	// не отрабатывает
}
// ---------------------------------------------------------------------
std::vector<int> As_Total_Score::Get()     // Метод должен возвращать строку
{
	std::vector<int> score_data;
	score_data.push_back(As_Total_Score::Total_Score);
	if (As_Total_Score::Total_Score > 0)
		score_data.push_back(As_Total_Score::Delta_Score);
	return score_data;         // Использовать интерполяцию
}




// ---------------------------------------------------------------------
std::vector<std::vector<std::string>> As_Record_Table::Get()
{
	std::string delimiter = ";";
	std::string file_path = "Records_Table.txt";
	std::vector<std::vector<std::string>> record_table;
	std::vector<std::vector<std::string>> record_table_with_title = {{"Data", "Record"}};
	std::ifstream fin(file_path.c_str());  

	if(fin.is_open())
	{
		std::string temp_string;
		while(getline(fin, temp_string))
		{	
			size_t pos = 0;
			std::string token;
			std::vector<std::string> record;
			while ((pos = temp_string.find(delimiter)) != std::string::npos) 
			{
			    token = temp_string.substr(0, pos);
			    record.push_back(token);
			    temp_string.erase(0, pos + delimiter.length());
			}
			record.push_back(temp_string);			
			record_table.push_back(record);
		}
	}
    fin.close();

	for (int j = 1; j < record_table.size(); j ++)
	{
		for (int i = 0; i < record_table.size() - j; i ++)
		{
			if (std::stoi(record_table[i][1]) < std::stoi(record_table[i + 1][1]))
			{
				std::vector<std::string> temp = record_table[i];
				record_table[i] = record_table[i + 1];
				record_table[i + 1] = temp; 
			}
		}
	}                
    record_table_with_title.insert(record_table_with_title.end(), record_table.begin(), record_table.end());
	
	return record_table_with_title;
}
// ---------------------------------------------------------------------
void As_Record_Table::Add_Record(int total_score)
{
	if (total_score > 0)
	{
		std::ofstream file_stream("Records_Table.txt", std::ios::app);
		std::time_t t = std::time(0);   
	    std::tm* now = std::localtime(&t);
	    
		file_stream << now->tm_mday << '-' << (now->tm_mon + 1) << '-' <<  (now->tm_year + 1900) << ";" 
					<< total_score << ";" << "\n";
	  	
		file_stream.close();	
	}
}  
