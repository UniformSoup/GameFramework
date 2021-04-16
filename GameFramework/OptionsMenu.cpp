#include "OptionsMenu.h"

void OptionsMenu::update(const Timing::duration& elapsed)
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
			back.update(e);
		case sf::Event::MouseButtonReleased:
			option.update(e);
			break;
		}
	}

	if (option.hasChanged())
		option.setText("Slider: " + std::to_string(option.getValue()));
		//std::cout << "Well Done. You clicked the option.\n";

	if (back.pressed())
	{
		states->pop();
		delete this; // this returns to the main menu
	}
	std::cout << "Elapsed Time: " << elapsed.count()/(1000.f * 1000.f) << "ms.\n";
};

void OptionsMenu::render()
{
	window->clear(sf::Color::Magenta);
	back.draw(*window);
	option.draw(*window);

	window->display();
};