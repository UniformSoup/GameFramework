#pragma once
#include "Menu.h"
#include "GameState.h"

class Game
{
private:
	sf::RenderWindow window;
	std::stack<GameState*> states;
	sf::Font f;

public:
	inline bool isPlaying() const { return window.isOpen(); };
	inline void update() { states.top()->update(); };
	inline void render() { states.top()->render(); };
	inline void run() { while (window.isOpen()) { update(); render(); } }
	// you should probably add a timer opr something here

	Game()
	{
		window.create(sf::VideoMode(960, 540), "Elliff is an Ape", sf::Style::Default | !sf::Style::Resize);
		f.loadFromFile("OCRAEXT.TTF");
		states.push(new Menu(&window, &states, &f));
	}

	~Game()
	{
		while (!states.empty())
		{
			delete states.top();
			states.pop();
		}
	}
};