#include "Menu.h"
#include "Game.h"
#include "OptionsMenu.h"

void Menu::update(const Timing::duration& elapsed)
{
	sf::Event e;
	while (pdata->window.pollEvent(e))
	{
		switch (e.type)
		{
		case sf::Event::Closed:
			pdata->window.close();
			break;

		case sf::Event::MouseMoved:
		case sf::Event::MouseButtonPressed:
			b.update(e);
			break;
		}
	}

	if (b.pressed())
		pdata->s.addState(new OptionsMenu(pdata));
}

void Menu::render()
{
	pdata->window.clear(sf::Color::Magenta);
	b.draw(pdata->window);
	pdata->window.display();
}

Menu::Menu(GameData* pData)
	: GameState(pData), b("Here is a button", pdata->f, { 100, 100, 760, 340 })
{}