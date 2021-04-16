#pragma once

#include "GameState.h"
#include "Button.h"
#include "Slider.h"

#include <iostream>

class OptionsMenu : public GameState
{
private:
	Button back;
	Slider option;
public:
	OptionsMenu(GameState* lastState)
		: GameState(lastState), option("Slider", *f, 0.5f, 100, 100, 760, 120), back("Go Back", *f, 100, 320, 760, 120)
	{}
	void update();
	void render();
};