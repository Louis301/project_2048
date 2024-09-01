#pragma once 
#include <vector>
#include <string>

// ----------------------------------------------------------------------------------------------------
class As_Record_Table
{
	public:
		static std::vector<std::vector<std::string> > Get();
		static void Add_Record(int total_score);
};
