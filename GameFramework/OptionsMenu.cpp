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
		case sf::Event::MouseButtonReleased:
			option.update(e);
			back.update(e);
			break;
		}
	}

	if (option.hasChanged())
		option.setText("Option: " + std::to_string(option.getValue()));
		//std::cout << "Well Done. You clicked the option.\n";

	if (back.pressed())
	{
		states->pop();
		delete this; // this returns to the main menu
	}
};

void OptionsMenu::render()
{
	window->clear(sf::Color::Magenta);
	back.draw(*window);
	option.draw(*window);

	window->display();
};