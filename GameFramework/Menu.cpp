#include "Menu.h"

void Menu::update()
{
	sf::Event e;
	while (window->pollEvent(e))
	{
		switch (e.type)
		{
		case sf::Event::Closed:
			window->close();
			break;

		case sf::Event::MouseMoved:
		case sf::Event::MouseButtonPressed:
			b.update(e);
			break;
		}
	}

	if (b.pressed())
		states->push(new OptionsMenu(this));
}

void Menu::render()
{
	window->clear();
	b.draw(*window);
	window->display();
}