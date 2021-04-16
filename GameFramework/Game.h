#pragma once
#include "Menu.h"
#include "GameState.h"
#include <assert.h>

#define FONTFILE "Assets/OCRAEXT.TTF"

class Game
{
private:
	sf::RenderWindow window;
	std::stack<GameState*> states;
	sf::Font f;
	sf::Clock clk;

public:
	inline bool isPlaying() const { return window.isOpen(); };
	inline void update() { states.top()->update(); };
	inline void render() { states.top()->render(); };
	void run(); 
	// you should probably add a timer or something here

	Game(); ~Game();
};