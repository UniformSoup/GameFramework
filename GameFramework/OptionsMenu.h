#pragma once

#include "GameState.h"
#include "Button.h"

#include <iostream>

class OptionsMenu : public GameState
{
private:
	Button option, back;
public:
	OptionsMenu(GameState* lastState)
		: GameState(lastState), option("An Option", *f, 100, 100, 760, 120), back("Go Back", *f, 100, 320, 760, 120)
	{}
	void update();
	void render();
};