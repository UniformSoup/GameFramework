#include "OptionsMenu.h"

void OptionsMenu::update()
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
			option.update(e);
			back.update(e);
			break;
		}
	}

	if (option.pressed())
		std::cout << "Well Done. You clicked the option.\n";

	if (back.pressed())
	{
		states->pop();
		delete this; // this returns to the main menu
	}
};

void OptionsMenu::render()
{
	window->clear();
	back.draw(*window);
	option.draw(*window);

	window->display();
};