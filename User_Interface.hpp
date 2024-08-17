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
		static int X_Offset;
		static int Y_Offset;
		
	public:
		static void Set_Draw_Position(int x_offset, int y_offset);
		static void Show_Dynamic(bool Color_Mode);
};
// ----------------------------------------------------------------------------------------------------
class As_UI_Control_Info      // ћожет, создать класс дл€ внутренних данных (смежный) ?
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
