#pragma once

enum EInteractionLayer
{
	EIL_Matrix_Management,
	EIL_Losing,
	EIL_Winning,
	EIL_Viewing_Results
};

class As_Program 
{
	private:
		static EInteractionLayer Interaction_Layer;
		
	public:
		static bool Exit_Program;
		
		static void Set_Internal_Data();
		static void Draw_UI();
		static void Start_Controller();
		
		static EInteractionLayer Get_Interaction_Layer();
		static void Set_Interaction_Layer(EInteractionLayer inter_layer);
};

