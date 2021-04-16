#pragma once
#include "Menu.h"
#include "GameState.h"
#include <assert.h>

#include "Timing.h"
#include <chrono>

#define FONTFILE "Assets/OCRAEXT.TTF"
#define WINDOWTITLE "Generic Game Title"



class Game
{
private:
	sf::RenderWindow window;
	std::stack<GameState*> states;
	sf::Font f;
	sf::Clock clk;
	Timing::Clock clock;

public:
	inline bool isPlaying() const { return window.isOpen(); };
	void run(); 

	Game(); ~Game();
};