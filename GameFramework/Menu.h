#pragma once

#include "Widgets/Button.h"
#include "GameState.h"
#include "OptionsMenu.h"

class Menu : public GameState
{
private:
	Button b;

public:
	Menu(GameData* pData, StateMachine<GameState>* s)
		: GameState(pData, s), b("Here is a button", pdata->f, { 100, 100, 760, 340 })
	{}
	void update(const Timing::duration& elapsed);
	void render();
};