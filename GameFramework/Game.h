#pragma once

#include "StateMachine.h"
#include "GameState.h"
#include "Timing.h"

#define FONTFILE "Assets/OCRAEXT.TTF"
#define WINDOWTITLE "Generic Game Title"

struct GameData
{
	sf::RenderWindow window;
	StateMachine<GameState> s;
	sf::Font f;
};

class Game
{
private:

	GameData data;
	Timing::Clock clock;

public:
	inline bool isPlaying() const { return data.window.isOpen(); };
	void run(); 

	Game();
};