//As_Program
//
//As_UI_Game_field
//As_UI_System_Msg
//As_UI_Record_Table
//As_UI_Total_Score
//As_UI_Control_Info
//
//As_2048_Field
//
//As_System_Msg
//
//As_Total_Score
//
//As_Record_Table
//
//CSVFile


//#include "Carriage.hpp"
//#include <CSVFile.hpp>
#include "Program.hpp"
#include <conio.h>


int main(int argc, char** argv) 
{
	As_Program::Set_Internal_Data();
	As_Program::Draw_UI();
	As_Program::Start_Controller();	
	
	getch();
	return 0;
}
