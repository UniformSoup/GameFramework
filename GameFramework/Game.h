#pragma once

#include "StateMachine.h"
#include "GameState.h"
#include "Timing.h"
#include "Menu.h"

#define FONTFILE "Assets/OCRAEXT.TTF"
#define WINDOWTITLE "Generic Game Title"

class Game
{
private:
	GameData data;
	StateMachine<GameState> s;
	Timing::Clock clock;

public:
	Game()
	{
		data.f.loadFromFile(FONTFILE);
		data.window.create(sf::VideoMode(960, 540), WINDOWTITLE, sf::Style::Default ^ sf::Style::Resize);

		s.addState(std::make_shared<Menu>(&data, &s));
		s.updateState();
	}

	inline int run()
	{
		while (data.window.isOpen())
		{
			s.getCurrentState().update(clock());
			s.getCurrentState().render();
			s.updateState();
		}

		return 0;
	}

	inline bool isPlaying() const { return data.window.isOpen(); };
};