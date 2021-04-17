#include "Game.h"
#include "Menu.h"

void Game::run()
{ 
	while (data.window.isOpen())
	{ 
		data.s.getCurrentState()->update(clock());
		data.s.getCurrentState()->render();
		data.s.updateState();
	}
}

Game::Game()
{
	data.f.loadFromFile(FONTFILE);
	data.window.create(sf::VideoMode(960, 540), WINDOWTITLE, sf::Style::Default ^ sf::Style::Resize);
	data.s.addState(new Menu(&data));
	data.s.updateState();
}