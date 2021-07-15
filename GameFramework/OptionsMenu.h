#pragma once

#include "Utilities/GameState.h"
#include "Widgets/Button.h"
#include "Widgets/Slider.h"

class OptionsMenu : public GameState
{
private:
	Button back;
	Slider option;

public:
	OptionsMenu(GameState* last) :
		GameState(last),
		option("Slider", pdata->f, 0.5f, { 100, 100, 760, 120 }),
		back("Go Back", pdata->f, { 100, 320, 760, 120 })
	{}
	void update(const Timing::duration& elapsed);
	void render();
};