#include "Total_Score.hpp"

// ---------------------------------------------------------------------    �� ���������� !
int As_Total_Score::Total_Score = 0;
int As_Total_Score::Delta_Score = 0;
// ---------------------------------------------------------------------
void As_Total_Score::Reset() 
{ 
	As_Total_Score::Total_Score = 0; 
}
// ---------------------------------------------------------------------
void As_Total_Score::Save_Up(int value)    // ��������
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
	// �� ������������
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
