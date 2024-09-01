#pragma once
#include <vector>

// ----------------------------------------------------------------------------------------------------
class As_Total_Score
{	
	private:
		static int Delta_Score;  
		static int Total_Score;	
	
	public:
		static void Reset();  	
		static std::vector<int> Get_With_Delta();
		static void Save_Up();
		static void Reset_Delta();
		static void Delta_Increment(int value);
		static int Get_Delta();
		static int Get();
};
