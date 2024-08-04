#include "Program.hpp"

int main(int argc, char** argv) 
{
	As_Program::Set_Internal_Data();
	As_Program::Draw_UI();
	As_Program::Start_Controller();	
	
	return 0;
}
