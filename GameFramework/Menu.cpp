#include "Menu.h"

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
		s->addState(std::make_shared<OptionsMenu>(this));
}

void Menu::render()
{
	pdata->window.clear(sf::Color::Magenta);
	b.draw(pdata->window);
	pdata->window.display();
}
