#pragma once

#include "GameState.h"
#include "Widgets/Button.h"
#include "Widgets/Slider.h"

#include <iostream>

class OptionsMenu : public GameState
{
private:
	Button back;
	Slider option;

public:
	OptionsMenu(GameData* pData);
	void update(const Timing::duration& elapsed);
	void render();
};