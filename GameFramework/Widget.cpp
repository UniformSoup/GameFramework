#include "Widget.h"

Widget::Widget(const std::string& name, const sf::Font& f, const unsigned int& charsz)
	: text(name, f, charsz)
{
	text.setFillColor(sf::Color::Black);
}