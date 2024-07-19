#include "CSVFile.hpp"

// ----------------------------------------------------------------------------------------------------
ACSVFile::ACSVFile(std::string path)
{
	Path = path;
	Content = "";
	Separator = ";";
}

// ----------------------------------------------------------------------------------------------------
void ACSVFile::Write(std::string &content)
{
	std::ofstream fout(Path.c_str());
	
	fout << content;
    
	fout.close();
}

// ----------------------------------------------------------------------------------------------------
void ACSVFile::Read(std::string &content)
{
	std::ifstream fin(Path.c_str());   

	if(fin.is_open())
	{
		std::string temp_string;
		
		while(getline(fin, temp_string))
            Content = Content + temp_string + '\n';
	}
            
    fin.close();
    
    content = Content;
}

