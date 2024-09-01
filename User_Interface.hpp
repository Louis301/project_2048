#pragma once
#include "Carriage.hpp"

// ----------------------------------------------------------------------------------------------------
class As_UI_System_Msg 
{
	private:
		static EColor _Color;
		static int _X_Offset;
		static int _Y_Offset;
		
	public:
		static void Set_Color(EColor color);
		static void Show_Dynamic(bool color_mode);
		static void Set_Draw_Position(int x_offset, int y_offset);
};
// ----------------------------------------------------------------------------------------------------
class As_UI_Control_Info 
{
	private:
		static int _X_Offset;
		static int _Y_Offset;
		
	public:
		static void Show_Static(bool color_mode);
		static void Set_Draw_Position(int x_offset, int y_offset);
};
// ----------------------------------------------------------------------------------------------------
class As_UI_Total_Score  
{
	private:
		static int _X_Offset;
		static int _Y_Offset;
		
	public:
		static void Show_Static(bool color_mode);
		static void Show_Dynamic(bool color_mode);
		static void Set_Draw_Position(int x_offset, int y_offset);
};
// ----------------------------------------------------------------------------------------------------
class As_UI_Record_Table 
{
	private:
		static int _X_Offset;
		static int _Y_Offset;
		
	public:
		static void Show_Static(bool color_mode);
		static void Set_Draw_Position(int x_offset, int y_offset);
};
// ----------------------------------------------------------------------------------------------------
class As_UI_Game_field 
{
	private:
		static int _X_Offset;
		static int _Y_Offset;
		
	public:
		static void Show_Static(bool color_mode);
		static void Show_Dynamic(bool color_mode);
		static void Set_Draw_Position(int x_offset, int y_offset);
};
