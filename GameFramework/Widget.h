#pragma once

#include <SFML/Graphics.hpp>
#include <string>

class Widget {
protected:
	sf::Text text;

	virtual void centerText() = 0;
	virtual bool isOver(const int& x, const int& y) const = 0;
	Widget(const std::string& name, const sf::Font& f, const unsigned int& charsz);

public:
	virtual void draw(sf::RenderWindow& window) = 0;
	virtual void update(const sf::Event& e) = 0;
};
