#include "InternalData.hpp"
#include <time.h>

bool As_Game_Field::Offset_Has_Been = false;
bool As_Game_Field::Have_2048 = false;
bool As_Game_Field::Offset_Is_Not_Possible = false;
int As_Game_Field::Delta_Score = 0;

const int As_Game_Field::N = 4;  // ������� ������� �������

std::vector<std::vector<int>> As_Game_Field::Game_Field;
std::vector<bool> As_Game_Field::Offset_Indicators = {true, true, true, true};

// ----------------------------------------------------------------------------------------------------
void As_Game_Field::Reset()
{
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
void As_Game_Field::Put_Element()   // ���� �� ������� ���� ����, ��������� 2 � 4
{
	srand(time(NULL));
	
	for (auto line : Game_Field)
	{
	 	for (auto item : line)
		{
		 	if (item == 0)    // ������� �������� ����
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
void As_Game_Field::Line_Elements_Offset(std::vector<int> &line, int delta_offset)   // �������� ��������� ����
{
	bool offset_has_been = false;    // �������� �������� (local var)
	int i = (delta_offset == -1) ? (i = N - 1) : (0);
    int j = i + delta_offset;	
	while ((delta_offset == -1) ? (i > 0 && j >= 0) : (i < N - 1 && j < N))
    {
    	if (line[j] == 0)
    	{
    		j += delta_offset;
		}
        else if (line[j] == line[i])   // ����� �������� ����������� ����. ����
        {
        	line[i] *= 2;
        	
			As_Game_Field::Delta_Score += line[i];	
        	
			if (line[i] == 2048)      // ��� ��������� ��������
				Have_2048 = true;
            
			i += delta_offset;
            line[j] = 0;
            j = i + delta_offset;
			offset_has_been = true;
		}
        else if (line[i] == 0)    // ����� �������� ����������� ����. ����
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
void As_Game_Field::Reverse()    // �������� ������� ������������ ������� ���������
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
void As_Game_Field::Offset(EOffsetDirection offset_direction)   // ������ �������� ������� � ��������� �����������
{
	As_Game_Field::Delta_Score = 0;
	
	Offset_Has_Been = false;   // ���� ����������, ��� �������� ����� �������. ������� false
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
	
	// ����� ��������, ������ �������� � ���������� ����������� ��� ���, � ����� �������� ������� 2048 ��� ���
	Offset_Indicators[offset_direction] = Offset_Has_Been;
	// ���� � ������� ����������� ��� �������  - �������� ����������
	for (auto item : Offset_Indicators)
		if (item == true)
			return;
	Offset_Is_Not_Possible = true;
	
	As_Total_Score::Set(As_Game_Field::Delta_Score);
}




// ----------------------------------------------------------------------------------------------------
std::string As_System_Message::System_Msg = "";
// ----------------------------------------------------------------------------------------------------
void As_System_Message::Reset()
{
	As_System_Message::Set("");
}
// ----------------------------------------------------------------------------------------------------
void As_System_Message::Set(std::string message)
{
	As_System_Message::System_Msg = message;
}
// ----------------------------------------------------------------------------------------------------
std::string As_System_Message::Get()
{
	return As_System_Message::System_Msg;
}




// ---------------------------------------------------------------------
int As_Total_Score::Total_Score = 0;
int As_Total_Score::Delta_Score = 0;
// ---------------------------------------------------------------------
void As_Total_Score::Reset()
{	
	As_Total_Score::Total_Score = 0;
}
// ---------------------------------------------------------------------
void As_Total_Score::Set(int delta_score)
{
	As_Total_Score::Total_Score += delta_score;
	As_Total_Score::Delta_Score = delta_score;
}
// ---------------------------------------------------------------------
std::vector<int> As_Total_Score::Get()     // ����� ������ ���������� ������
{
	std::vector<int> score_data;
	
	score_data.push_back(As_Total_Score::Total_Score);
	
	if (As_Total_Score::Total_Score > 0)
		score_data.push_back(As_Total_Score::Delta_Score);
	
	return score_data;         // ������������ ������������
}




// ---------------------------------------------------------------------
void As_Record_Table::Reset()
{
	// control tabel logic
}

