#include "Record_Table.hpp"
#include <fstream>
#include <ctime>

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
			std::vector<std::string> record;
			
			if (temp_string != "")
			{
				size_t pos = 0;
				std::string token;
//				std::vector<std::string> record;
				while ((pos = temp_string.find(delimiter)) != std::string::npos) 
				{
				    token = temp_string.substr(0, pos);
				    record.push_back(token);
				    temp_string.erase(0, pos + delimiter.length());
				}
				record.push_back(temp_string);	
			}
			else
			{
				record.push_back({"",""});	
			}
			
			record_table.push_back(record);
		}
	}
    fin.close();

	for (int j = 1; j < record_table.size(); j ++)     // —ортировка значащей части таблицы по столбцу "—чЄт"
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
		std::ofstream file_stream("Records_Table.txt", std::ios::app);  // дописывыем строку во внешний файл (в файле только значаща€ часть таблицы счЄта)
		std::time_t t = std::time(0);   
	    std::tm* now = std::localtime(&t);
	    
		file_stream << now->tm_mday << '-' << (now->tm_mon + 1) << '-' <<  (now->tm_year + 1900) << ";" 
					<< total_score << ";" << "\n";
	  	
		file_stream.close();	
	}
}
