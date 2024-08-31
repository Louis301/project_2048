#pragma once



//constexpr EInteractionLayer Interaction_Layer = EIL_Matrix_Management;

class Key_Handler
{
//	public:	
	
	public:
		static void On_Esc();
		static void On_Up();
		static void On_Down();
		static void On_Left();
		static void On_Right();
		static void On_C();
		static void On_R();
		static void On_Space();
		
};


// 
// обрабочики клавишь должны перегружаться в зависимости от слоя взаимодействия
//
//
//
//
