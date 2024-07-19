#pragma once


enum EInteractionLayer
{
	EIL_Main_Screen,
	EIL_Record_Table_Screen
};


class Key_Handler
{
	private:
		static EInteractionLayer Interaction_Layer;
	
	public:
		static void On_Esc();
		static void On_Up();
		static void On_Down();
		static void On_Left();
		static void On_Right();
		static void On_C();
		static void On_R();
};
