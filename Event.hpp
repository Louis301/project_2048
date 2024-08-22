#pragma once
#include "InternalData.hpp"


class As_Event
{
	public:
		static void Stop_Program();
		static void Show_Record_Table();
		static void Continue_Game();
		static void Restart_Game();
		static void Game_Field_Interaction(EOffsetDirection);
		static void You_Fail();
		static void You_Win();
};
