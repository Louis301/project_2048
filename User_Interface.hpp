#pragma once


//class UI_Component
//{
//	protected:
//		static int X_Offset;
//		static int Y_Offset;
//		
//		static void Show();	
//		static void Draw_Dynamic();	
//		static void Hide();
//		static void Set_Draw_Position(int x_offset, int y_offset);
//};


// ----------------------------------------------------------------------------------------------------
class As_UI_Game_field
{
	public:
		static void Show();
		static void Hide_Dynamic();
		static void Show_Dynamic();
		static void Show_Static();
//		Print_Dynamic
//		Print_Static
};

// ----------------------------------------------------------------------------------------------------
class As_UI_System_Msg
{
	public:
	static void Show();
};

// ----------------------------------------------------------------------------------------------------
class As_UI_Control_Info
{
	public:
	static void Show();
};

// ----------------------------------------------------------------------------------------------------
class As_UI_Total_Score
{	
	public:
	static void Show();
};
