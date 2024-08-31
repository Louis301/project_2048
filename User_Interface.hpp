#pragma once
#include "Carriage.hpp"
#include <iostream>

// ----------------------------------------------------------------------------------------------------
class As_UI_Game_field
{
	private:
		static int X_Offset;
		static int Y_Offset;
		
	public:
		static void Set_Draw_Position(int x_offset, int y_offset);
		static void Show_Dynamic(bool Color_Mode);
		static void Show_Static(bool Color_Mode);
};
// ----------------------------------------------------------------------------------------------------
class As_UI_System_Msg
{
	private:
		static int    _X_Offset;
		static int    _Y_Offset;
		static EColor _Color;
		
	public:
		static void Set_Draw_Position(int x_offset, int y_offset);
		static void Show_Dynamic(bool Color_Mode);
		static void Set_Color(EColor color);
};
// ----------------------------------------------------------------------------------------------------
class As_UI_Control_Info     
{
	private:
		static int X_Offset;
		static int Y_Offset;
		
	public:
		static void Set_Draw_Position(int x_offset, int y_offset);
		static void Show_Static(bool Color_Mode);
};
// ----------------------------------------------------------------------------------------------------
class As_UI_Total_Score
{	
	private:
		static int X_Offset;
		static int Y_Offset;
		
	public:
		static void Set_Draw_Position(int x_offset, int y_offset);
		static void Show_Static(bool Color_Mode);
		static void Show_Dynamic(bool Color_Mode);
};
// ----------------------------------------------------------------------------------------------------
class As_UI_Record_Table
{
	private:
		static int    _X_Offset;
		static int    _Y_Offset;
		
	public:
		static void Set_Draw_Position(int x_offset, int y_offset);
		static void Show_Static(bool color_mode);
};
