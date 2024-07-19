#pragma once
#include <iostream>
#include <vector>
#include <fstream>
#include <string>

class ACSVFile
{	
public:
	ACSVFile(std::string path);
	
//	void Add_Row(std::vector<std::string> columns);
	void Read(std::string &content);
	void Write(std::string &content);
	
	std::string Separator;
	
private:
	std::string Path, Content;
};

