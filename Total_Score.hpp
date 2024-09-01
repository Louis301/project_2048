#pragma once
#include <vector>

// ----------------------------------------------------------------------------------------------------
class As_Total_Score
{	
	private:
		static int Delta_Score;  // реализовать алгоритм с дельтой. Возможно, проблема в ИДЕ
	
	public:
		static void Reset();  					// Сбрасывает счёт до нулевого
		static std::vector<int> Get();
		static void Save_Up(int value);
		static void Reset_Delta();
		static void Delta_Increment(int value);
		static int Get_Delta();
		
		static int Total_Score;	
};
