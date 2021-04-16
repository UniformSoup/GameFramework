#pragma once

#include <SFML/Graphics.hpp>
#include <string>

#include "Widget.h"

class Button : public Widget {
private:
	sf::RectangleShape r;
	sf::Color colour = sf::Color::White;
	bool isPressed = false;
	void centerText();

public:
	Button(const std::string& name, const sf::Font& f, const float& x, const float& y, const float& w, const float& h, const unsigned int& charsz = 30U);
	void draw(sf::RenderWindow& window);
	void update(const sf::Event& e);
	void setText(const std::string& s);
	void setCharSize(const unsigned int& charsz);
	inline bool pressed();
};

inline bool Button::pressed()
{
	bool temp = isPressed;
	isPressed = false;
	return temp;
}