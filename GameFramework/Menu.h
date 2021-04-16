#pragma once

#include "Widgets/Button.h"
#include "GameState.h"
#include "OptionsMenu.h"

class Menu : public GameState
{
private:
	Button b;
public:
	Menu(sf::RenderWindow* t_window, std::stack<GameState*>* t_states, sf::Font* t_f)
		: GameState(t_window, t_states, t_f), b("Ask Someone Else Next Time", *f, 100, 100, 760, 340)
	{}
	void update(const Timing::duration& elapsed);
	void render();
};


