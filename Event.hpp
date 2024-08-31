#pragma once
#include "InternalData.hpp"
#include "Program.hpp"

//enum EInteractionLayer
//{
//	EIL_Matrix_Management,
//	EIL_Losing,
//	EIL_Winning,
//	EIL_Viewing_Results
//};
//
//
//		static EInteractionLayer Interaction_Layer;

class As_Event
{
//	private:
//		static EInteractionLayer Interaction_Layer;
		
	public:
		static void Stop_Program();
		static void Continue_Game();
		static void Restart_Game();
		static void Game_Field_Interaction(EOffsetDirection);
		static void You_Fail();
		static void You_Win();
		static void Record_Table_Interaction();
		
//		static EInteractionLayer Get_Interaction_Layer();
//		static void Set_Interaction_Layer(EInteractionLayer inter_layer);
};
