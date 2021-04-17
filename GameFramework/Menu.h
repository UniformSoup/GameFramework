#pragma once

#include "Widgets/Button.h"
#include "GameState.h"

class Menu : public GameState
{
private:
	Button b;
public:
	Menu(GameData* pData);
	void update(const Timing::duration& elapsed);
	void render();
};


