#include "OptionsMenu.h"
#include "Game.h"

void OptionsMenu::update(const Timing::duration& elapsed)
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
			back.update(e);
		case sf::Event::MouseButtonReleased:
			option.update(e);
			break;
		default:
			break;
		}
	}

	if (option.hasChanged())
		option.setText("Slider: " + std::to_string(option.getValue()));
		//std::cout << "Well Done. You clicked the option.\n";

	if (back.pressed())
		pdata->s.removeState();

	std::cout << "Elapsed Time: " << elapsed.count()/(1000.f * 1000.f) << "ms.\n";
};

void OptionsMenu::render()
{
	pdata->window.clear(sf::Color::Magenta);
	back.draw(pdata->window);
	option.draw(pdata->window);

	pdata->window.display();
};

OptionsMenu::OptionsMenu(GameData* pData)
	: GameState(pData), option("Slider", pdata->f, 0.5f, { 100, 100, 760, 120 }), back("Go Back", pdata->f, { 100, 320, 760, 120 })
{}