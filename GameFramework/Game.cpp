#include "Game.h"

void Game::run()
{ 
	while (window.isOpen())
	{ 
		assert(!states.empty());
		update();
		render();
	}
}

Game::Game()
{
	f.loadFromFile(FONTFILE);
	window.create(sf::VideoMode(960, 540), WINDOWTITLE, sf::Style::Default ^ sf::Style::Resize);
	states.push(new Menu(&window, &states, &f));
}

Game::~Game()
{
	while (!states.empty())
	{
		delete states.top();
		states.pop();
	}
}